// Super Ugly Number

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* dp = (int*)malloc(n * sizeof(int));
    int* pointers = (int*)calloc(primesSize, sizeof(int));
    
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        long long minVal = LLONG_MAX;
        for (int j = 0; j < primesSize; j++) {
            long long candidate = (long long)dp[pointers[j]] * primes[j];
            if (candidate < minVal) {
                minVal = candidate;
            }
        }
        dp[i] = (int)minVal;
        
        for (int j = 0; j < primesSize; j++) {
            long long candidate = (long long)dp[pointers[j]] * primes[j];
            if (candidate == minVal) {
                pointers[j]++;
            }
        }
    }
    
    int result = dp[n-1];
    free(dp);
    free(pointers);
    return result;
}

int main() {
    int n, primesSize;
    printf("Enter n: ");
    scanf("%d", &n);
    
    printf("Enter the size of primes array: ");
    scanf("%d", &primesSize);
    
    int* primes = (int*)malloc(primesSize * sizeof(int));
    printf("Enter the primes (space separated): ");
    for (int i = 0; i < primesSize; i++) {
        scanf("%d", &primes[i]);
    }
    
    int result = nthSuperUglyNumber(n, primes, primesSize);
    printf("The %dth super ugly number is: %d\n", n, result);
    
    free(primes);
    return 0;
}