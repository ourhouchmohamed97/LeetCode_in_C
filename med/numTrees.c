// Unique Binary Search Trees

#include <stdio.h>
#include <stdlib.h>

int numTrees(int n) {
    if (n <= 1) return 1;
    
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    int result = dp[n];
    free(dp);
    return result;
}

int main() {
    int n;
    printf("Enter the number of nodes (1 <= n <= 19): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 19) {
        printf("Invalid input. Please enter a number between 1 and 19.\n");
        return 1;
    }
    
    int result = numTrees(n);
    printf("The number of structurally unique BSTs with %d nodes is: %d\n", n, result);
    
    return 0;
}