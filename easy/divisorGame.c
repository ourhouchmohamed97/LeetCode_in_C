// Divisor Game

#include <stdio.h>
#include <stdbool.h>

bool divisorGame(int n) {
    if (n == 1) return false;
    bool dp[n+1];
    dp[1] = false;
    for (int i = 2; i <= n; i++) {
        dp[i] = false;
        for (int x = 1; x < i; x++) {
            if (i % x == 0) {
                if (!dp[i - x]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
}

int main() {
    printf("%s\n", divisorGame(2) ? "true" : "false");
    printf("%s\n", divisorGame(3) ? "true" : "false");
    return 0;
}