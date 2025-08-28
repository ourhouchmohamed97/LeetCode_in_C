// Ugly Number II

#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; i++) {
        int next2 = dp[i2] * 2;
        int next3 = dp[i3] * 3;
        int next5 = dp[i5] * 5;
        int next = next2;
        if (next3 < next) next = next3;
        if (next5 < next) next = next5;
        dp[i] = next;
        if (next == next2) i2++;
        if (next == next3) i3++;
        if (next == next5) i5++;
    }
    int result = dp[n-1];
    free(dp);
    return result;
}

int main() {
    int n = 10;
    printf("The %dth ugly number is %d\n", n, nthUglyNumber(n));
    return 0;
}