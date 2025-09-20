// Implement Router

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int source;
    int destination;
    int timestamp;
} Packet;

typedef struct {
    int s, d, t;
    int state;
} HashEntry;

typedef struct DestNode {
    int dest;
    int *ts;
    int head;
    int size;
    int cap;
    struct DestNode *next;
} DestNode;

typedef struct {
    int memoryLimit;
    int size;
    Packet *queue;
    int front, rear;

    HashEntry *dupHash;
    int dupCap;

    DestNode **destBuckets;
    int destCap;
} Router;

/* ---------- helpers: hashing ---------- */
static unsigned long mix3(unsigned long a, unsigned long b, unsigned long c) {
    unsigned long x = a;
    x = (x * 11400714819323198485ull) + b;
    x ^= (c + 0x9e3779b97f4a7c15ULL + (x << 6) + (x >> 2));
    return x;
}

static inline int dupIndex(Router *r, int s, int d, int t) {
    return (int)(mix3((unsigned long)s, (unsigned long)d, (unsigned long)t) % (unsigned long)r->dupCap);
}

/* ---------- dest hash (chaining) ---------- */
static inline int destBucketIdx(Router *r, int dest) {
    int x = dest % r->destCap;
    if (x < 0) x += r->destCap;
    return x;
}

static DestNode* findDestNode(Router *r, int dest) {
    int idx = destBucketIdx(r, dest);
    DestNode *cur = r->destBuckets[idx];
    while (cur) {
        if (cur->dest == dest) return cur;
        cur = cur->next;
    }
    return NULL;
}

static DestNode* createDestNode(Router *r, int dest) {
    int idx = destBucketIdx(r, dest);
    DestNode *n = (DestNode*)malloc(sizeof(DestNode));
    n->dest = dest;
    n->cap = 4;
    n->ts = (int*)malloc(sizeof(int) * n->cap);
    n->head = 0;
    n->size = 0;
    n->next = r->destBuckets[idx];
    r->destBuckets[idx] = n;
    return n;
}

/* append timestamp (timestamps are non-decreasing globally) */
static void destAppend(Router *r, int dest, int timestamp) {
    DestNode *n = findDestNode(r, dest);
    if (!n) n = createDestNode(r, dest);
    // Ensure space at position head+size
    if (n->head + n->size >= n->cap) {
        // If there is unused head space, compact first
        if (n->head > 0) {
            memmove(n->ts, n->ts + n->head, sizeof(int) * n->size);
            n->head = 0;
        }
        // still full -> resize
        if (n->head + n->size >= n->cap) {
            n->cap *= 2;
            n->ts = (int*)realloc(n->ts, sizeof(int) * n->cap);
        }
    }
    n->ts[n->head + n->size] = timestamp;
    n->size++;
}

/* remove timestamp - usually will be at head (oldest for that dest),
   fallback to searching and removing if not at head */
static void destRemove(Router *r, int dest, int timestamp) {
    DestNode *n = findDestNode(r, dest);
    if (!n || n->size == 0) return;
    if (n->ts[n->head] == timestamp) {
        n->head++;
        n->size--;
        // optionally compact when head grows too large
        if (n->head > 64 && n->head > n->cap / 2) {
            memmove(n->ts, n->ts + n->head, sizeof(int) * n->size);
            n->head = 0;
        }
        return;
    }
    // fallback: search linearly (rare because of monotonic timestamps)
    int i;
    for (i = 0; i < n->size; ++i) {
        if (n->ts[n->head + i] == timestamp) break;
    }
    if (i == n->size) return; // not found
    int idx = n->head + i;
    memmove(n->ts + idx, n->ts + idx + 1, sizeof(int) * (n->size - i - 1));
    n->size--;
    // no change to head
}

/* binary search helpers on [0..size-1] mapped to actual index head+mid */
static int lowerBoundDest(DestNode *n, int value) {
    int lo = 0, hi = n->size;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int v = n->ts[n->head + mid];
        if (v < value) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
static int upperBoundDest(DestNode *n, int value) {
    int lo = 0, hi = n->size;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int v = n->ts[n->head + mid];
        if (v <= value) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

/* ---------- duplicate hash table (open addressing, linear probe, tombstones) ---------- */
static bool dupContains(Router *r, int s, int d, int t) {
    int start = dupIndex(r, s, d, t);
    for (int i = 0; i < r->dupCap; ++i) {
        int j = (start + i) % r->dupCap;
        HashEntry *e = &r->dupHash[j];
        if (e->state == 0) return false; // empty slot => not present
        if (e->state == 1 && e->s == s && e->d == d && e->t == t) return true;
        // tombstone or different occupied => continue probing
    }
    return false;
}

static bool dupInsert(Router *r, int s, int d, int t) {
    int start = dupIndex(r, s, d, t);
    int firstDeleted = -1;
    for (int i = 0; i < r->dupCap; ++i) {
        int j = (start + i) % r->dupCap;
        HashEntry *e = &r->dupHash[j];
        if (e->state == 1) {
            if (e->s == s && e->d == d && e->t == t) return false; // already present
            continue;
        }
        if (e->state == 2) {
            if (firstDeleted == -1) firstDeleted = j;
            continue;
        }
        // empty slot
        int pos = (firstDeleted != -1) ? firstDeleted : j;
        r->dupHash[pos].s = s;
        r->dupHash[pos].d = d;
        r->dupHash[pos].t = t;
        r->dupHash[pos].state = 1;
        return true;
    }
    // table full (shouldn't happen with chosen sizing)
    return false;
}

static void dupRemove(Router *r, int s, int d, int t) {
    int start = dupIndex(r, s, d, t);
    for (int i = 0; i < r->dupCap; ++i) {
        int j = (start + i) % r->dupCap;
        HashEntry *e = &r->dupHash[j];
        if (e->state == 0) return; // not found
        if (e->state == 1 && e->s == s && e->d == d && e->t == t) {
            e->state = 2; // tombstone
            return;
        }
    }
}

/* ---------- API functions ---------- */

Router* routerCreate(int memoryLimit) {
    Router *r = (Router*)malloc(sizeof(Router));
    r->memoryLimit = memoryLimit;
    r->size = 0;
    r->queue = (Packet*)malloc(sizeof(Packet) * memoryLimit);
    r->front = 0;
    r->rear = -1;

    r->dupCap = memoryLimit * 4 + 7;
    if (r->dupCap < 8) r->dupCap = 8;
    r->dupHash = (HashEntry*)malloc(sizeof(HashEntry) * r->dupCap);
    for (int i = 0; i < r->dupCap; ++i) r->dupHash[i].state = 0;

    r->destCap = memoryLimit * 2 + 7;
    if (r->destCap < 8) r->destCap = 8;
    r->destBuckets = (DestNode**)calloc(r->destCap, sizeof(DestNode*));
    return r;
}

bool routerAddPacket(Router* obj, int source, int destination, int timestamp) {
    if (dupContains(obj, source, destination, timestamp)) return false;

    // If full, evict oldest
    if (obj->size == obj->memoryLimit) {
        Packet old = obj->queue[obj->front];
        // pop front
        obj->front = (obj->front + 1) % obj->memoryLimit;
        obj->size--;
        // remove from structures
        dupRemove(obj, old.source, old.destination, old.timestamp);
        destRemove(obj, old.destination, old.timestamp);
    }

    // push new packet
    obj->rear = (obj->rear + 1) % obj->memoryLimit;
    obj->queue[obj->rear].source = source;
    obj->queue[obj->rear].destination = destination;
    obj->queue[obj->rear].timestamp = timestamp;
    obj->size++;

    // update destination timestamps and duplicate hash
    destAppend(obj, destination, timestamp);
    dupInsert(obj, source, destination, timestamp);

    return true;
}

int* routerForwardPacket(Router* obj, int* retSize) {
    if (obj->size == 0) {
        *retSize = 0;
        return NULL;
    }
    Packet p = obj->queue[obj->front];
    obj->front = (obj->front + 1) % obj->memoryLimit;
    obj->size--;

    // remove from structures
    dupRemove(obj, p.source, p.destination, p.timestamp);
    destRemove(obj, p.destination, p.timestamp);

    int *res = (int*)malloc(sizeof(int) * 3);
    res[0] = p.source;
    res[1] = p.destination;
    res[2] = p.timestamp;
    *retSize = 3;
    return res;
}

int routerGetCount(Router* obj, int destination, int startTime, int endTime) {
    DestNode *n = findDestNode(obj, destination);
    if (!n || n->size == 0) return 0;
    int left = lowerBoundDest(n, startTime);
    int right = upperBoundDest(n, endTime);
    return right - left;
}

void routerFree(Router* obj) {
    // free dest nodes
    for (int i = 0; i < obj->destCap; ++i) {
        DestNode *cur = obj->destBuckets[i];
        while (cur) {
            DestNode *tmp = cur;
            cur = cur->next;
            free(tmp->ts);
            free(tmp);
        }
    }
    free(obj->destBuckets);
    free(obj->dupHash);
    free(obj->queue);
    free(obj);
}

int main() {
    Router* r = routerCreate(3);

    printf("%d\n", routerAddPacket(r, 1, 2, 10)); // 1
    printf("%d\n", routerAddPacket(r, 2, 3, 20)); // 1
    printf("%d\n", routerAddPacket(r, 1, 2, 10)); // 0 (duplicate)
    printf("%d\n", routerAddPacket(r, 3, 2, 30)); // 1

    int retSize;
    int* p = routerForwardPacket(r, &retSize);
    if (p) {
        printf("Forwarded: %d %d %d\n", p[0], p[1], p[2]);
        free(p);
    }

    printf("Count dest=2, [5,25]: %d\n", routerGetCount(r, 2, 5, 25));

    routerFree(r);
    return 0;
}
