// Cyclically Rotating a Grid


int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize;
    int n = gridColSize[0];
    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int)); 
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][j];
        }

    }

    for (int layer = 0; layer < (m < n ? m : n) / 2; layer++) {
        int maxSize = 2 * (m + n);
        int* r = (int*)malloc(maxSize * sizeof(int));
        int* c = (int*)malloc(maxSize * sizeof(int));
        int* val = (int*)malloc(maxSize * sizeof(int));
        int total = 0;

        for (int i = layer; i < m - layer - 1; i++) {
            r[total] = i;
            c[total] = layer;
            val[total++] = res[i][layer];
        }

        for (int j = layer; j < n - layer - 1; j++) {
            r[total] = m - layer - 1;
            c[total] = j;
            val[total++] = res[m - layer - 1][j];
        }

        for (int i = m - layer - 1; i > layer; i--) {
            r[total] = i;
            c[total] = n - layer - 1;
            val[total++] = res[i][n - layer - 1];

        }

        for (int j = n - layer - 1; j > layer; j--) {
            r[total] = layer;
            c[total] = j;
            val[total++] = res[layer][j];

        }

        int kk = k % total;
        for (int i = 0; i < total; i++) {
            int idx = (i + total - kk) % total;
            res[r[i]][c[i]] = val[idx];
        }
        free(r);
        free(c);
        free(val);

    }
    *returnSize = m;
    return res;
}