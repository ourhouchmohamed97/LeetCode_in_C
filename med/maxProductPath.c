int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    const int MOD = 1000000007;

    long long** Min = malloc(m * sizeof(long long*));
    long long** Max = malloc(m * sizeof(long long*));

    for (int i = 0; i < m; i++) {
        Min[i] = malloc(n * sizeof(long long));
        Max[i] = malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            Min[i][j] = LLONG_MAX;
            Max[i][j] = LLONG_MIN;
        }
    }

    Min[0][0] = Max[0][0] = grid[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) 
                continue;

            long long mn = LLONG_MAX;
            long long mx = LLONG_MIN;

            if (i > 0) {
                long long a = Min[i-1][j] * grid[i][j];
                long long b = Max[i-1][j] * grid[i][j];
                if (a < mn) mn = a;
                if (b < mn) mn = b;
                if (a > mx) mx = a;
                if (b > mx) mx = b;
            }

            if (j > 0) {
                long long a = Min[i][j-1] * grid[i][j];
                long long b = Max[i][j-1] * grid[i][j];
                if (a < mn) mn = a;
                if (b < mn) mn = b;
                if (a > mx) mx = a;
                if (b > mx) mx = b;
            }

            Min[i][j] = mn;
            Max[i][j] = mx;
        }
    }

    long long res = Max[m-1][n-1];
    return res >= 0 ? res % MOD : -1;
}
