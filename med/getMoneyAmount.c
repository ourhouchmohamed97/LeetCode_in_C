// Guess Number Higher or Lower II

#include <stdio.h>
#include <limits.h>

int getMoneyAmount(int n) {
    int dp[n+2][n+2];

    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++) {
            dp[i][j] = 0;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int start = 1; start + len - 1 <= n; start++) {
            int end = start + len - 1;
            dp[start][end] = INT_MAX;

            for (int x = start; x <= end; x++) {
                int cost = x + (x-1 >= start ? dp[start][x-1] : 0);
                int right = (x+1 <= end ? dp[x+1][end] : 0);
                if (right > (x-1 >= start ? dp[start][x-1] : 0)) {
                    cost = x + right;
                }
                if (cost < dp[start][end]) {
                    dp[start][end] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    printf("n = 10 → %d\n", getMoneyAmount(10)); // Expected 16
    printf("n = 1 → %d\n", getMoneyAmount(1));   // Expected 0
    printf("n = 2 → %d\n", getMoneyAmount(2));   // Expected 1
    return 0;
}
