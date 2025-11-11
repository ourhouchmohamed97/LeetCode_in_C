// Ones and Zeroes

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int k = 0; k < strsSize; k++) {
        int zeros = 0, ones = 0;
        for (char* p = strs[k]; *p; p++) {
            if (*p == '0') zeros++;
            else ones++;
        }

        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                if (dp[i - zeros][j - ones] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - zeros][j - ones] + 1;
                }
            }
        }
    }

    return dp[m][n];
}
