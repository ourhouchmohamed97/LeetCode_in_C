// Delete Columns to Make Sorted III

#include <stdlib.h>
#include <string.h>

int minDeletionSize(char** strs, int strsSize) {
    int n = (int)strlen(strs[0]);
    int* dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int ok = 1;
            for (int r = 0; r < strsSize; r++) {
                if (strs[r][j] > strs[r][i]) { ok = 0; break; }
            }
            if (ok && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) if (dp[i] > mx) mx = dp[i];
    free(dp);
    return n - mx;
}
