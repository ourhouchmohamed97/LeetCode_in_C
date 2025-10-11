// Maximum Total Damage With Spell Casting

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long maximumTotalDamage(int* power, int powerSize) {
    if (powerSize == 0) return 0;
    
    qsort(power, powerSize, sizeof(int), cmp);
    
    // Count totals per unique value
    int *unique = malloc(powerSize * sizeof(int));
    long long *total = malloc(powerSize * sizeof(long long));
    int n = 0;
    unique[0] = power[0];
    total[0] = power[0];
    for (int i = 1; i < powerSize; i++) {
        if (power[i] == unique[n]) total[n] += power[i];
        else {
            n++;
            unique[n] = power[i];
            total[n] = power[i];
        }
    }
    n++;
    
    long long *dp = calloc(n, sizeof(long long));
    dp[0] = total[0];
    
    for (int i = 1; i < n; i++) {
        // find last compatible j
        int j = i - 1;
        while (j >= 0 && unique[i] - unique[j] <= 2) j--;
        
        long long include = total[i] + (j >= 0 ? dp[j] : 0);
        long long exclude = dp[i - 1];
        dp[i] = (include > exclude) ? include : exclude;
    }
    
    long long ans = dp[n - 1];
    free(unique);
    free(total);
    free(dp);
    return ans;
}

int main() {
    int p1[] = {1,1,3,4};
    printf("%lld\n", maximumTotalDamage(p1, 4)); // 6

    int p2[] = {7,1,6,6};
    printf("%lld\n", maximumTotalDamage(p2, 4)); // 13

    int p3[] = {5,9,2,10,2,7,10,9,3,8};
    printf("%lld\n", maximumTotalDamage(p3, 10)); // ✅ 31
}
