// Climbing Stairs

#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

int main() {
    int n1 = 2;
    printf("Number of ways to climb %d steps: %d\n", n1, climbStairs(n1)); // Output: 2

    int n2 = 3;
    printf("Number of ways to climb %d steps: %d\n", n2, climbStairs(n2)); // Output: 3

    int n3 = 5;
    printf("Number of ways to climb %d steps: %d\n", n3, climbStairs(n3)); // Output: 8

    return 0;
}