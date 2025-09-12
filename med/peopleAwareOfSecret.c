// Number of People Aware of a Secret

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    long long *dp = calloc(n + 1, sizeof(long long));
    dp[1] = 1; // Day 1: first person knows the secret
    
    long long sharing = 0; // current sharers
    for (int day = 2; day <= n; day++) {
        // people who start sharing today
        if (day - delay >= 1) {
            sharing = (sharing + dp[day - delay]) % MOD;
        }
        // people who forget today (stop sharing)
        if (day - forget >= 1) {
            sharing = (sharing - dp[day - forget] + MOD) % MOD;
        }
        // new people who learn today
        dp[day] = sharing;
    }
    
    long long ans = 0;
    // Count people who still remember on day n
    for (int i = n - forget + 1; i <= n; i++) {
        if (i >= 1) ans = (ans + dp[i]) % MOD;
    }
    
    free(dp);
    return (int)ans;
}

// Example usage
int main() {
    printf("%d\n", peopleAwareOfSecret(6, 2, 4)); // Output: 5
    printf("%d\n", peopleAwareOfSecret(4, 1, 3)); // Output: 6
    return 0;
}
