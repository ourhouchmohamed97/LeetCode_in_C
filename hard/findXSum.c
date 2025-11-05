// Find X-Sum of All K-Long Subarrays II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    int f;    
    long long v;   
} Item;

static inline int top_priority(const Item *a, const Item *b) {
    if (a -> f != b -> f) {
        return a -> f < b -> f;  
    }    
    return a -> v < b -> v;                        
}

static inline int rest_priority(const Item *a, const Item *b) {
    if (a -> f != b -> f) {
        return a -> f > b -> f;   
    }
    return a -> v > b -> v;                         
}

typedef struct {
    Item *a;
    int sz;
    int cap;
    int (*priority)(const Item*, const Item*);
} Heap;

static void heap_init(Heap *h, int cap, int (*priority)(const Item*, const Item*)) {
    h -> cap = cap < 16 ? 16 : cap;
    h -> a = (Item*)malloc(sizeof(Item) * h -> cap);
    h -> sz = 0;
    h -> priority = priority;
}

static void heap_free(Heap *h) { 
    free(h -> a); 
    h -> a = NULL; 
    h -> sz = h -> cap = 0; 
}

static void heap_grow(Heap *h) {
    if (h -> sz + 4 >= h -> cap) {
        h -> cap *= 2;
        h -> a = (Item*)realloc(h -> a, sizeof(Item) * h -> cap);
    }
}

static void heap_push(Heap *h, Item it) {
    heap_grow(h);
    int i = h -> sz++;
    h -> a[i] = it;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (h -> priority(&h -> a[i], &h -> a[p])) {
            Item tmp = h -> a[i]; 
            h -> a[i] = h -> a[p]; 
            h -> a[p] = tmp;
            i = p;
        } else break;
    }
}

static Item heap_top(const Heap *h) { 
    return h -> a[0]; 
}

static int heap_empty(const Heap *h) { 
    return h -> sz == 0; 
}

static void heap_pop(Heap *h) {
    if (h -> sz == 0) {
        return;
    }
    h -> a[0] = h -> a[--h -> sz];
    int i = 0;
    while (true) {
        int l = i * 2 + 1, r = l + 1, best = i;
        if (l < h -> sz && h -> priority(&h -> a[l], &h -> a[best])) {
            best = l;
        }
        if (r < h -> sz && h -> priority(&h -> a[r], &h -> a[best])) {
            best = r;
        }
        if (best == i) break;
        Item tmp = h -> a[i];
        h -> a[i] = h -> a[best]; 
        h -> a[best] = tmp; 
        i = best;
    }
}

static int cmp_ll(const void *a, const void *b) {
    long long va = *(const long long*)a, vb = *(const long long*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

static int value_to_id(long long *uniq, int m, long long v) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (uniq[mid] == v) {
            return mid;
        }
        if (uniq[mid] < v) {
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

long long* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    if (numsSize == 0) { 
        *returnSize = 0; 
        return NULL; }
    *returnSize = numsSize - k + 1;
    long long *ans = (long long*)malloc(sizeof(long long) * (*returnSize));

    if (k == x) {
        long long s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        ans[0] = s;
        for (int i = k; i < numsSize; ++i) {
            s += nums[i] - nums[i - k];
            ans[i - k + 1] = s;
        }
        return ans;
    }

    long long *tmp = (long long*)malloc(sizeof(long long) * numsSize);
    for (int i = 0; i < numsSize; ++i) tmp[i] = (long long)nums[i];
    qsort(tmp, numsSize, sizeof(long long), cmp_ll);
    int m = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i == 0 || tmp[i] != tmp[i-1]) {
            tmp[m++] = tmp[i];
        }
    }
    long long *uniq = tmp;

    int *freq = (int*)calloc(m, sizeof(int));
    char *inTop = (char*)calloc(m, sizeof(char));

    Heap top, rest;
    heap_init(&top, m * 2 + 16, top_priority);
    heap_init(&rest, m * 2 + 16, rest_priority);

    for (int i = 0; i < k; ++i) {
        int id = value_to_id(uniq, m, nums[i]);
        freq[id]++;
    }

    for (int id = 0; id < m; ++id) {
        if (freq[id] > 0) {
            Item it = { id, freq[id], uniq[id] };
            heap_push(&rest, it);
        }
    }

    long long xSum = 0;
    int inTopCount = 0;

    while (inTopCount < x) {
        while (!heap_empty(&rest)) {
            Item it = heap_top(&rest);
            int id = it.id;
            if (it.f != freq[id] || it.f <= 0 || inTop[id]) { heap_pop(&rest); continue; }
            heap_pop(&rest);
            inTop[id] = 1;
            ++inTopCount;
            xSum += (long long)freq[id] * uniq[id];
            Item nit = { id, freq[id], uniq[id] };
            heap_push(&top, nit);
            break;
        }
        if (heap_empty(&rest)) break;
    }

    while (true) {
        while (!heap_empty(&top)) {
            Item it = heap_top(&top);
            int id = it.id;
            if (it.f != freq[id] || it.f <= 0 || !inTop[id]) { 
                heap_pop(&top); 
                continue; 
            }
            break;
        }

        while (!heap_empty(&rest)) {
            Item it = heap_top(&rest);
            int id = it.id;
            if (it.f != freq[id] || it.f <= 0 || inTop[id]) { 
                heap_pop(&rest); 
                continue; 
            }
            break;
        }

        if (heap_empty(&top) || heap_empty(&rest)) {
            break;
        }
        Item worst = heap_top(&top);
        Item best = heap_top(&rest);
        int wid = worst.id, bid = best.id;
        if (!(worst.f == freq[wid] && inTop[wid] && best.f == freq[bid] && !inTop[bid])) {
            if (!(worst.f == freq[wid] && inTop[wid])) heap_pop(&top);
            if (!(best.f == freq[bid] && !inTop[bid])) heap_pop(&rest);
            continue;
        }
        int do_swap = 0;
        if (best.f > worst.f) {
            do_swap = 1;
        } else if (best.f == worst.f && uniq[bid] > uniq[wid]) {
            do_swap = 1;
        }
        if (!do_swap) break;
        heap_pop(&top); 
        heap_pop(&rest);
        inTop[wid] = 0; 
        inTop[bid] = 1;
        xSum -= (long long)worst.f * uniq[wid];
        xSum += (long long)best.f * uniq[bid];
        Item nw = { wid, freq[wid], uniq[wid] };
        Item nb = { bid, freq[bid], uniq[bid] };
        heap_push(&rest, nw);
        heap_push(&top, nb);
    }

    ans[0] = xSum;

    for (int i = k; i < numsSize; ++i) {
        long long outv = nums[i - k];
        long long inv = nums[i];
        int outId = value_to_id(uniq, m, outv);
        int inId = value_to_id(uniq, m, inv);

        if (inTop[outId]) {
            xSum -= uniq[outId];
        }
        freq[outId]--;
        if (freq[outId] > 0) {
            Item nit = { outId, freq[outId], uniq[outId] };
            heap_push(&rest, nit);
            heap_push(&top, nit);
        } else {
            if (inTop[outId]) { inTop[outId] = 0; --inTopCount; }
        }

        freq[inId]++;
        if (inTop[inId]) xSum += uniq[inId];
        Item inIt = { inId, freq[inId], uniq[inId] };
        heap_push(&rest, inIt);
        heap_push(&top, inIt);

        while (inTopCount < x) {
            while (!heap_empty(&rest)) {
                Item it = heap_top(&rest);
                int id = it.id;
                if (it.f != freq[id] || it.f <= 0 || inTop[id]) { 
                    heap_pop(&rest); 
                    continue; 
                }
                heap_pop(&rest);
                inTop[id] = 1;
                ++inTopCount;
                xSum += (long long)freq[id] * uniq[id];
                Item nit = { id, freq[id], uniq[id] };
                heap_push(&top, nit);
                break;
            }
            if (heap_empty(&rest)) break;
        }

        while (true) {
            while (!heap_empty(&top)) {
                Item it = heap_top(&top);
                int id = it.id;
                if (it.f != freq[id] || it.f <= 0 || !inTop[id]) { 
                    heap_pop(&top); 
                    continue; 
                }
                break;
            }
            while (!heap_empty(&rest)) {
                Item it = heap_top(&rest);
                int id = it.id;
                if (it.f != freq[id] || it.f <= 0 || inTop[id]) { 
                    heap_pop(&rest); 
                    continue; 
                }
                break;
            }
            if (heap_empty(&top) || heap_empty(&rest)) break;
            Item worst = heap_top(&top);
            Item best = heap_top(&rest);
            int wid = worst.id, bid = best.id;
            if (!(worst.f == freq[wid] && inTop[wid] && best.f == freq[bid] && !inTop[bid])) {
                if (!(worst.f == freq[wid] && inTop[wid])) heap_pop(&top);
                if (!(best.f == freq[bid] && !inTop[bid])) heap_pop(&rest);
                continue;
            }
            int do_swap = 0;
            if (best.f > worst.f) {
                do_swap = 1;
            } else if (best.f == worst.f && uniq[bid] > uniq[wid]) {
                do_swap = 1;
            }
            if (!do_swap) break;
            heap_pop(&top); 
            heap_pop(&rest);
            inTop[wid] = 0; 
            inTop[bid] = 1;
            xSum -= (long long)worst.f * uniq[wid];
            xSum += (long long)best.f * uniq[bid];
            Item nw = { wid, freq[wid], uniq[wid] };
            Item nb = { bid, freq[bid], uniq[bid] };
            heap_push(&rest, nw);
            heap_push(&top, nb);
        }

        if (inTopCount > x) {
            while (inTopCount > x) {
                while (!heap_empty(&top)) {
                    Item it = heap_top(&top);
                    int id = it.id;
                    if (it.f != freq[id] || it.f <= 0 || !inTop[id]) { 
                        heap_pop(&top); 
                        continue; 
                    }
                    heap_pop(&top);
                    inTop[id] = 0;
                    --inTopCount;
                    xSum -= (long long)it.f * uniq[id];
                    Item nw = { id, freq[id], uniq[id] };
                    heap_push(&rest, nw);
                    break;
                }
                if (heap_empty(&top)) break;
            }
        }
        ans[i - k + 1] = xSum;
    }

    free(freq);
    free(inTop);
    free(uniq);
    heap_free(&top);
    heap_free(&rest);
    return ans;
}