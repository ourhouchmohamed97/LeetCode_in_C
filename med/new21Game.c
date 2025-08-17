// New 21 Game

#include <stdio.h>
#include <stdlib.h>

double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k - 1 + maxPts) {
        return 1.0;
    }

    double *dp = (double *)calloc(n + 1, sizeof(double));
    if (!dp) return 0.0;
    dp[0] = 1.0;
    double windowSum = 1.0;
    double result = 0.0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = windowSum / maxPts;

        if (i < k) {
            windowSum += dp[i];
        } else {
            result += dp[i];
        }

        if (i - maxPts >= 0) {
            windowSum -= dp[i - maxPts];
        }
    }

    free(dp);
    return result;
}

int main() {
    printf("%.5f\n", new21Game(10, 1, 10)); // Output: 1.00000
    printf("%.5f\n", new21Game(6, 1, 10));  // Output: 0.60000
    printf("%.5f\n", new21Game(21, 17, 10)); // Output: 0.73278
    return 0;
}