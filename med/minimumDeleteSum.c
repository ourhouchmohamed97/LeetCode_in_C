// Minimum ASCII Delete Sum for Two Strings

#include <stdlib.h>
#include <string.h>

int minimumDeleteSum(char* s1, char* s2)
{
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n + 1][m + 1];

    // Base case: s1 finished
    dp[n][m] = 0;
    for (int j = m - 1; j >= 0; j--)
        dp[n][j] = dp[n][j + 1] + s2[j];

    // Base case: s2 finished
    for (int i = n - 1; i >= 0; i--)
        dp[i][m] = dp[i + 1][m] + s1[i];

    // Fill DP table
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
            {
                int delete_s1 = s1[i] + dp[i + 1][j];
                int delete_s2 = s2[j] + dp[i][j + 1];
                dp[i][j] = delete_s1 < delete_s2 ? delete_s1 : delete_s2;
            }
        }
    }

    return dp[0][0];
}
