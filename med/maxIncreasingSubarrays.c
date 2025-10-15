// Adjacent Increasing Subarrays Detection II

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool exists(int *inc, int numsSize, int k) {
    for (int a = 0; a + 2 * k <= numsSize; a++) {
        if (inc[a] >= k && inc[a + k] >= k)
            return true;
    }
    return false;
}

int maxIncreasingSubarrays(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;

    int *inc = malloc(sizeof(int) * numsSize);
    if (!inc) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    inc[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            inc[i] = inc[i + 1] + 1;
        else
            inc[i] = 1;
    }

    int left = 1;
    int right = numsSize / 2;
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (exists(inc, numsSize, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    free(inc);
    return ans;
}

int main(void) {
    int nums[] = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maxIncreasingSubarrays(nums, n);
    printf("Result: %d\n", result); // Expected output: 3

    // Try another example
    int nums2[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Result: %d\n", maxIncreasingSubarrays(nums2, n2)); // Expected: 2

    return 0;
}
