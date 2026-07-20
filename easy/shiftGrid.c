// Shift 2D Grid

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int m = gridColSize[0];

    int** res = malloc(n * sizeof(int*));
    *returnColumnSizes = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        res[i] = calloc(m, sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int newJ = (j + k) % m;
            int newI = (i + (j + k) / m) % n;

            res[newI][newJ] = grid[i][j];
        }
    }

    *returnSize = n;
    return res;

}