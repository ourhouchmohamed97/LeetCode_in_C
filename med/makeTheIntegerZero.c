// Minimum Operations to Make the Integer Zero

#include <stdio.h>
#include <stdint.h>

int makeTheIntegerZero(int num1, int num2) {
    for (int k = 0; k <= 60; k++) {
        int64_t S = (int64_t)num1 - (int64_t)k * num2;
        if (S < 0) continue;
        int bits = 0;
        int64_t n = S;
        while (n) {
            bits += n & 1;
            n >>= 1;
        }
        if (bits <= k && k <= S) {
            return k;
        }
    }
    return -1;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int result = makeTheIntegerZero(num1, num2);
    printf("%d\n", result);
    return 0;
}