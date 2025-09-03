// Perfect Squares

#include <stdio.h>
#include <limits.h>

int numSquares(int n) {
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j*j <= i; j++) {
            if (dp[i - j*j] + 1 < dp[i]) {
                dp[i] = dp[i - j*j] + 1;
            }
        }
    }
    return dp[n];
}

int main() {
    int n1 = 12;
    printf("Input: n = %d\n", n1);
    printf("Output: %d\n\n", numSquares(n1));

    int n2 = 13;
    printf("Input: n = %d\n", n2);
    printf("Output: %d\n\n", numSquares(n2));

    return 0;
}