// Ways to Express an Integer as Sum of Powers

#include <math.h>
#include <string.h>
#include <stdio.h>

int numberOfWays(int n, int x) {
    int mod = 1e9 + 7;
    int max_i = 1;
    while (pow(max_i, x) <= n) {
        max_i++;
    }
    max_i--;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= max_i; i++) {
        int power = (int)pow(i, x);
        for (int j = n; j >= power; j--) {
            dp[j] = (dp[j] + dp[j - power]) % mod;
        }
    }
    return dp[n];
}

int main() {
    int n, x;
    printf("Enter n and x: ");
    scanf("%d %d", &n, &x);
    int result = numberOfWays(n, x);
    printf("Number of ways: %d\n", result);
    return 0;
}