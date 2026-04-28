// Minimum Operations to Make a Uni-Value Grid

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int total = gridSize * gridColSize[0];
    int* res = (int*)malloc(total * sizeof(int));
    int idx = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            res[idx++] = grid[i][j];
        }
    }
    int mod = res[0] % x;

    for (int i = 0; i < total; i++) {
        if (res[i] % x != mod) {
            free(res);
            return -1;
        }
    }
    qsort(res, total, sizeof(int), cmp);
    int m = res[total / 2];
    int cnt = 0;
    for (int i = 0; i < total; i++) {
        cnt += abs(res[i] - m) / x;
    }
    free(res);
    return cnt;
}