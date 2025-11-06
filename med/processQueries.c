// Power Grid Maintenance


typedef struct {
    int* parent;
    int size;
} DSU;

DSU* dsuCreate(int size) {
    DSU* obj = (DSU*)malloc(sizeof(DSU));
    obj->size = size;
    obj->parent = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        obj->parent[i] = i;
    }
    return obj;
}

int dsuFind(DSU* obj, int x) {
    if (obj->parent[x] != x) {
        obj->parent[x] = dsuFind(obj, obj->parent[x]);
    }
    return obj->parent[x];
}

void dsuJoin(DSU* obj, int u, int v) {
    obj->parent[dsuFind(obj, v)] = dsuFind(obj, u);
}

void dsuFree(DSU* obj) {
    free(obj->parent);
    free(obj);
}

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int* processQueries(int c, int** connections, int connectionsSize,
                    int* connectionsColSize, int** queries, int queriesSize,
                    int* queriesColSize, int* returnSize) {
    DSU* dsu = dsuCreate(c + 1);
    for (int i = 0; i < connectionsSize; i++) {
        dsuJoin(dsu, connections[i][0], connections[i][1]);
    }

    bool* online = (bool*)malloc((c + 1) * sizeof(bool));
    int* offlineCounts = (int*)calloc(c + 1, sizeof(int));
    for (int i = 0; i <= c; i++) {
        online[i] = true;
    }

    HashItem* minimumOnlineStations = NULL;
    for (int i = 0; i < queriesSize; i++) {
        int op = queries[i][0];
        int x = queries[i][1];
        if (op == 2) {
            online[x] = false;
            offlineCounts[x]++;
        }
    }

    for (int i = 1; i <= c; i++) {
        int root = dsuFind(dsu, i);
        if (!hashFindItem(&minimumOnlineStations, root)) {
            hashAddItem(&minimumOnlineStations, root, -1);
        }
        int station = hashGetItem(&minimumOnlineStations, root, -1);
        if (online[i]) {
            if (station == -1 || station > i) {
                hashSetItem(&minimumOnlineStations, root, i);
            }
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    int ansSize = 0;
    for (int i = queriesSize - 1; i >= 0; i--) {
        int op = queries[i][0];
        int x = queries[i][1];
        int root = dsuFind(dsu, x);
        int station = hashGetItem(&minimumOnlineStations, root, -1);

        if (op == 1) {
            if (online[x]) {
                ans[ansSize++] = x;
            } else {
                ans[ansSize++] = station;
            }
        }

        if (op == 2) {
            if (offlineCounts[x] > 1) {
                offlineCounts[x]--;
            } else {
                online[x] = true;
                if (station == -1 || station > x) {
                    hashSetItem(&minimumOnlineStations, root, x);
                }
            }
        }
    }

    for (int i = 0, j = ansSize - 1; i < j; i++, j--) {
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
    }

    *returnSize = ansSize;
    dsuFree(dsu);
    free(online);
    free(offlineCounts);
    hashFree(&minimumOnlineStations);

    return ans;
}