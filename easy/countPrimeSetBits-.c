// Prime Number of Set Bits in Binary Representation

#include <stdbool.h>

static int popcount(unsigned int x) {
    int c = 0;
    while (x) {
        x &= (x - 1);
        c++;
    }
    return c;
}

static bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

int countPrimeSetBits(int left, int right) {
    int res = 0;
    for (int i = left; i <= right; i++) {
        int bits = popcount((unsigned)i);
        if (isPrime(bits)) res++;
    }
    return res;
}