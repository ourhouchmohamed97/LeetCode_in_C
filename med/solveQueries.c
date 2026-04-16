// Closest Equal Element Queries

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    int n = numsSize;
    int* dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        dp[i] = n;

    int* last = (int*)malloc(100001 * sizeof(int));
    for (int i = 0; i < 100001; i++) last[i] = -1;

    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n;
        int num = nums[idx];

        if (last[num] != -1) {
            int prev = last[num];
            int dist = i - prev;

            if (dist < dp[idx]) dp[idx] = dist;
            if (dist < dp[prev % n]) dp[prev % n] = dist;
        }

        last[num] = i;
    }

    int* res = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int q = queries[i];
        res[i] = (dp[q] == n) ? -1 : dp[q];
    }

    *returnSize = queriesSize;

    free(dp);
    free(last);
    return res;
}