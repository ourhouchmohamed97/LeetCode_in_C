// Block Placement Queries

static inline int max_val(int a, int b) {
    return (a > b) ? a : b;
}

static inline void update(int* tree, int n, int i, int val) {
    i += n;
    tree[i] = val;
    while (i > 1) {
        tree[i >> 1] = max_val(tree[i], tree[i ^ 1]);
        i >>= 1;
    }
}

static inline int query(int* tree, int n, int r) {
    int res = 0;
    for (int l = n, r_idx = r + n + 1; l < r_idx; l >>= 1, r_idx >>= 1) {
        if (l & 1) {
            res = max_val(res, tree[l++]);
        }
        if (r_idx & 1) {
            res = max_val(res, tree[--r_idx]);
        }
    }
    return res;
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int max_x = 0;
    for (int i = 0; i < queriesSize; i++) {
        if (queries[i][1] > max_x) {
            max_x = queries[i][1];
        }
    }

    int n = 1;
    while (n <= max_x + 1) {
        n <<= 1;
    }
    
    int* tree = (int*)calloc(2 * n, sizeof(int));
    int* obstacles = (int*)malloc((queriesSize + 1) * sizeof(int));
    
    obstacles[0] = 0;
    int obsCount = 1;

    bool* res = (bool*)malloc(queriesSize * sizeof(bool));
    int retSize = 0;

    for (int i = 0; i < queriesSize; i++) {
        int type = queries[i][0];
        int x = queries[i][1];

        int l = 0, r = obsCount;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (obstacles[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int idx = l; 

        if (type == 1) {
            int prev = obstacles[idx - 1];
            int nxt = (idx < obsCount) ? obstacles[idx] : -1;

            update(tree, n, x, x - prev);
            if (nxt != -1) {
                update(tree, n, nxt, nxt - x);
            }

            memmove(&obstacles[idx + 1], &obstacles[idx], (obsCount - idx) * sizeof(int));
            obstacles[idx] = x;
            obsCount++;
        } else {
            int sz = queries[i][2];
            int prev = obstacles[idx - 1];
            int mx = max_val(x - prev, query(tree, n, prev));
            res[retSize++] = (sz <= mx);
        }
    }

    *returnSize = retSize;
    free(obstacles);
    free(tree);
    return res;
}
