// Paths in Matrix Whose Sum Is Divisible by K

#define MOD 1000000007

int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    // Allocate 3D dp: dp[m][n][k], initialized to 0
    int ***dp = (int ***)malloc(m * sizeof(int **));
    for (int i = 0; i < m; ++i) {
        dp[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; ++j) {
            dp[i][j] = (int *)calloc(k, sizeof(int));
        }
    }

    // Initialize starting cell
    int rem0 = ((grid[0][0] % k) + k) % k;
    dp[0][0][rem0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;

            int val = ((grid[i][j] % k) + k) % k;

            for (int r_prev = 0; r_prev < k; ++r_prev) {
                int from_top = 0, from_left = 0;

                if (i > 0) {
                    from_top = dp[i - 1][j][r_prev];
                }
                if (j > 0) {
                    from_left = dp[i][j - 1][r_prev];
                }

                if (from_top || from_left) {
                    int r = (r_prev + val) % k;
                    long long add = ( (long long)from_top + from_left ) % MOD;
                    dp[i][j][r] = (dp[i][j][r] + (int)add) % MOD;
                }
            }
        }
    }

    int ans = dp[m - 1][n - 1][0];

    // Free memory
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}