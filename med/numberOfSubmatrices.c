int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int* ox = calloc(n, sizeof(int));
    int* oy = calloc(n, sizeof(int));

    int res = 0;

    for (int i = 0; i < m; i++) {
        int rowX = 0, rowY = 0;

        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X')
                rowX++;
            else if (grid[i][j] == 'Y')
                rowY++;

            ox[j] += rowX;
            oy[j] += rowY;

            if (ox[j] == oy[j] && ox[j] > 0)
                res++;
        }
    }

    free(ox);
    free(oy);
    return res;
}
