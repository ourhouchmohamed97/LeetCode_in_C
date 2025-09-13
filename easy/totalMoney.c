// Calculate Money in Leetcode Bank

#include <stdio.h>

int totalMoney(int n) {
    if (n <= 0) return 0;

    int weeks = n / 7;
    int rem = n % 7;

    long long total = 0;

    total += (long long)weeks * 28;
    total += 7LL * weeks * (weeks - 1) / 2;

    total += (long long)rem * (1 + weeks) + (long long)rem * (rem - 1) / 2;

    return (int)total;
}

int main(void) {
    printf("%d\n", totalMoney(4));   // 10
    printf("%d\n", totalMoney(10));  // 37
    printf("%d\n", totalMoney(20));  // 96
    return 0;
}
