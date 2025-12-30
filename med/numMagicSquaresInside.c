// Magic Squares In Grid

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int r = gridSize, c = gridColSize[0];
    if (r < 3 || c < 3) return 0;

    int ans = 0;
    for (int i = 0; i + 2 < r; i++) {
        for (int j = 0; j + 2 < c; j++) {
            int used[10] = {0};
            int ok = 1;

            for (int x = 0; x < 3 && ok; x++) {
                for (int y = 0; y < 3; y++) {
                    int v = grid[i + x][j + y];
                    if (v < 1 || v > 9 || used[v]) {
                        ok = 0;
                        break;
                    }
                    used[v] = 1;
                }
            }
            if (!ok) continue;

            int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            for (int x = 0; x < 3; x++)
                if (grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2] != s) ok = 0;
            for (int y = 0; y < 3; y++)
                if (grid[i][j+y] + grid[i+1][j+y] + grid[i+2][j+y] != s) ok = 0;
            if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) ok = 0;
            if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) ok = 0;

            if (ok) ans++;
        }
    }
    return ans;
}