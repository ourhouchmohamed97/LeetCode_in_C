// Prime Arrangements

#include <stdio.h>
#include <stdbool.h>

const int MOD = 1000000007;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

long long factorial(int num) {
    long long result = 1;
    for (int i = 2; i <= num; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int numPrimeArrangements(int n) {
    int primeCount = 0;
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            primeCount++;
        }
    }
    int nonPrimeCount = n - primeCount;
    long long factPrimes = factorial(primeCount);
    long long factNonPrimes = factorial(nonPrimeCount);
    return (factPrimes * factNonPrimes) % MOD;
}

int main() {
    int n1 = 5;
    int n2 = 100;
    
    printf("Example 1: n = %d, Output: %d\n", n1, numPrimeArrangements(n1));
    printf("Example 2: n = %d, Output: %d\n", n2, numPrimeArrangements(n2));
    
    return 0;
}