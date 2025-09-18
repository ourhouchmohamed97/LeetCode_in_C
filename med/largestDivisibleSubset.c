// Largest Divisible Subset

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    long long x = *(int*)a;
    long long y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int* dp = calloc(numsSize, sizeof(int));
    int* prev = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
    int maxLen = 1, maxIdx = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }
    int* ans = malloc(sizeof(int) * maxLen);
    int k = maxLen - 1;
    int idx = maxIdx;
    while (idx != -1) {
        ans[k--] = nums[idx];
        idx = prev[idx];
    }
    *returnSize = maxLen;
    free(dp);
    free(prev);
    return ans;
}

int main() {
    int nums1[] = {1,2,3};
    int size1;
    int* res1 = largestDivisibleSubset(nums1, 3, &size1);
    for (int i = 0; i < size1; i++) printf("%d ", res1[i]);
    printf("\n");
    free(res1);

    int nums2[] = {1,2,4,8};
    int size2;
    int* res2 = largestDivisibleSubset(nums2, 4, &size2);
    for (int i = 0; i < size2; i++) printf("%d ", res2[i]);
    printf("\n");
    free(res2);

    return 0;
}