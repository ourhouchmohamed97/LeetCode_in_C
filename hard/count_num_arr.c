// Count the Number of Arrays with K Matching Adjacent Elements

#include <stdio.h>
#define MOD 1000000007
#define MAX 100005

long long fact[MAX], invFact[MAX];

long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

void precomputeFactorials(int max) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= max; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = power(fact[i], MOD - 2);
    }
}

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int countGoodArrays(int n, int m, int k) {
    precomputeFactorials(n);
    long long c = comb(n - 1, k);
    long long res = c * m % MOD * power(m - 1, n - k - 1) % MOD;
    return (int)res;
}

// Example usage
int main() {
    printf("%d\n", countGoodArrays(3, 2, 1));       // 4
    printf("%d\n", countGoodArrays(4, 2, 2));       // 6
    printf("%d\n", countGoodArrays(5, 2, 0));       // 2
    printf("%d\n", countGoodArrays(40603, 16984, 29979)); // Handles large input efficiently
    return 0;
}
