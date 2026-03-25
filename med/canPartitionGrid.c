bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    long long total = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }

    if (total % 2 != 0) {
        return 0;
    }

    long long target = total / 2;
    long long curr = 0;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            curr += grid[i][j];
        }
        if (curr == target) {
            return 1;
        }
    }

    curr = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) {
            curr += grid[i][j];
        }
        if (curr == target) {
            return 1;
        }
    }

    return 0;
}
