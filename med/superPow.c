// Super Power

#include <stdio.h>

#define MOD 1337

int modPow(int a, int k) {
    long res = 1;
    long base = a % MOD;
    while (k > 0) {
        if (k % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        k /= 2;
    }
    return (int)res;
}

int superPow(int a, int* b, int bSize) {
    if (bSize == 0) return 1;
    int lastDigit = b[bSize - 1];
    int part1 = modPow(a, lastDigit);
    int part2 = modPow(superPow(a, b, bSize - 1), 10);
    return (part1 * part2) % MOD;
}

int main() {
    int a = 2;
    int b1[] = {3};
    int b2[] = {1,0};
    int b3[] = {4,3,3,8,5,2};
    printf("%d\n", superPow(a, b1, 1));
    printf("%d\n", superPow(a, b2, 2));
    printf("%d\n", superPow(1, b3, 6));
    return 0;
}
