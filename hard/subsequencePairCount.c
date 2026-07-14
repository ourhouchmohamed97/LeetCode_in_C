// Find the Number of Subsequences With Equal GCD

#include <stdlib.h>
#include <string.h>

#define MAX_GCD 201
#define MOD 1000000007

int nums[1000];
int n;
int memo[1000][MAX_GCD][MAX_GCD];

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int dfs(int i, int a, int b) {
    if (i == n) {
        return (a > 0 && a == b) ? 1 : 0;
    }

    if (memo[i][a][b] != -1) {
        return memo[i][a][b];
    }

    int val = nums[i];
    long long ans = dfs(i + 1, a, b);
    ans += dfs(i + 1, gcd(a, val), b);
    ans += dfs(i + 1, a, gcd(b, val));

    return memo[i][a][b] = (int)(ans % MOD);
}

int subsequencePairCount(int* nums_arr, int numsSize) {
    n = numsSize;
    
    for (int i = 0; i < n; i++) {
        nums[i] = nums_arr[i];
    }

    memset(memo, -1, n * MAX_GCD * MAX_GCD * sizeof(int));

    return dfs(0, 0, 0);
}