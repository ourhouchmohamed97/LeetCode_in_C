// Maximum Square Area by Removing Fences From a Field

static int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

// Simple hash set for int (open addressing)
typedef struct {
    int* keys;
    char* used;
    int size;
} HashSet;

HashSet* createSet(int cap) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->size = cap;
    set->keys = (int*)malloc(sizeof(int) * cap);
    set->used = (char*)calloc(cap, 1);
    return set;
}

int hashInt(int x, int size) {
    long long v = (long long)x * 2654435761ULL;
    return (int)(v % size);
}

void setAdd(HashSet* set, int key) {
    int idx = hashInt(key, set->size);
    while (set->used[idx]) {
        if (set->keys[idx] == key)
            return;
        idx = (idx + 1) % set->size;
    }
    set->used[idx] = 1;
    set->keys[idx] = key;
}

bool setContains(HashSet* set, int key) {
    int idx = hashInt(key, set->size);
    while (set->used[idx]) {
        if (set->keys[idx] == key)
            return true;
        idx = (idx + 1) % set->size;
    }
    return false;
}

int* prepare(int* arr, int n, int limit, int* outSize) {
    qsort(arr, n, sizeof(int), cmp);
    int* result = (int*)malloc((n + 2) * sizeof(int));
    result[0] = 1;
    for (int i = 0; i < n; i++)
        result[i + 1] = arr[i];
    result[n + 1] = limit;
    *outSize = n + 2;
    return result;
}

int maximizeSquareArea(int height, int width, int* hFences, int hSize,
                       int* vFences, int vSize) {
    const long long MOD = 1000000007LL;

    int H, V;
    int* h = prepare(hFences, hSize, height, &H);
    int* v = prepare(vFences, vSize, width, &V);

    // worst-case horizontal distances count = H*(H-1)/2
    int maxPairs = (H * (H - 1)) / 2;
    HashSet* set = createSet(maxPairs * 2 + 1);

    // generate horizontal distances
    for (int i = 0; i < H; i++) {
        for (int j = i + 1; j < H; j++) {
            setAdd(set, h[j] - h[i]);
        }
    }

    long long best = 0;

    // match vertical distances
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            int diff = v[j] - v[i];
            if (diff > best && setContains(set, diff)) {
                best = diff;
            }
        }
    }

    free(h);
    free(v);
    free(set->keys);
    free(set->used);
    free(set);

    if (best == 0)
        return -1;

    long long ans = (best * best) % MOD;
    return (int)ans;
}