// Minimum Operations to Make Array Elements Zero

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll compute_operations(ll l, ll r) {
    ll total_steps = 0;
    ll max_k = 0;
    ll k = 1;
    while (1) {
        ll low_k = (k == 1) ? 1 : (1LL << (2 * (k-1)));
        ll high_k = (1LL << (2 * k)) - 1;
        if (low_k > r) break;
        if (high_k < l) {
            k++;
            continue;
        }
        ll seg_l = (l > low_k) ? l : low_k;
        ll seg_r = (r < high_k) ? r : high_k;
        if (seg_l <= seg_r) {
            ll count = seg_r - seg_l + 1;
            total_steps += count * k;
            if (k > max_k) max_k = k;
        }
        k++;
    }
    ll ops = (max_k > (total_steps + 1) / 2) ? max_k : (total_steps + 1) / 2;
    return ops;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    ll ans = 0;
    for (int i = 0; i < queriesSize; i++) {
        ll l = queries[i][0];
        ll r = queries[i][1];
        ans += compute_operations(l, r);
    }
    return ans;
}

int main() {
    // Example 1: queries = [[1,2],[2,4]]
    int numQueries1 = 2;
    int* queries1[2];
    int colSizes1[2] = {2, 3};
    
    queries1[0] = (int*)malloc(2 * sizeof(int));
    queries1[0][0] = 1;
    queries1[0][1] = 2;
    
    queries1[1] = (int*)malloc(3 * sizeof(int));
    queries1[1][0] = 2;
    queries1[1][1] = 3;
    queries1[1][2] = 4;
    
    ll result1 = minOperations(queries1, numQueries1, colSizes1);
    printf("Example 1 Output: %lld\n", result1); // Expected: 3
    
    // Free allocated memory for example 1
    free(queries1[0]);
    free(queries1[1]);
    
    // Example 2: queries = [[2,6]]
    int numQueries2 = 1;
    int* queries2[1];
    int colSizes2[1] = {5};
    
    queries2[0] = (int*)malloc(5 * sizeof(int));
    queries2[0][0] = 2;
    queries2[0][1] = 3;
    queries2[0][2] = 4;
    queries2[0][3] = 5;
    queries2[0][4] = 6;
    
    ll result2 = minOperations(queries2, numQueries2, colSizes2);
    printf("Example 2 Output: %lld\n", result2); // Expected: 4
    
    // Free allocated memory for example 2
    free(queries2[0]);
    
    return 0;
}