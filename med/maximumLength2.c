// Find the Maximum Length of Valid Subsequence II

#include <stdio.h>
#include <stdlib.h>

int maximumLength(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;

    int **dp = malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        dp[i] = calloc(k, sizeof(int));
    }

    int max_len = 1;
    for (int i = 0; i < numsSize; i++) {
        int m = nums[i] % k;
        int *new_lengths = calloc(k, sizeof(int));

        for (int S = 0; S < k; S++) {
            int r = (S - m + k) % k;
            new_lengths[S] = (dp[S][r] > 0) ? dp[S][r] + 1 : 1;
        }

        for (int S = 0; S < k; S++) {
            if (new_lengths[S] > dp[S][m]) {
                dp[S][m] = new_lengths[S];
                if (dp[S][m] > max_len) max_len = dp[S][m];
            }
        }
        free(new_lengths);
    }

    for (int i = 0; i < k; i++) free(dp[i]);
    free(dp);

    return max_len;
}


int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int k1 = 2;
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: Output = %d\n", maximumLength(nums1, len1, k1)); // Expected: 5

    int nums2[] = {1, 4, 2, 3, 1, 4};
    int k2 = 3;
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: Output = %d\n", maximumLength(nums2, len2, k2)); // Expected: 4

    int nums3[] = {3, 6, 3, 6, 3};
    int k3 = 3;
    printf("Custom Test: Output = %d\n", maximumLength(nums3, 5, k3)); // Expected: 5

    return 0;
}