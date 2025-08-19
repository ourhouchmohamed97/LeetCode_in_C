// Number of Zero-Filled Subarrays

#include <stdio.h>

long long zeroFilledSubarray(int* nums, int numsSize) {
    long long result = 0;
    long long current = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            current++;
            result += current;
        } else {
            current = 0;
        }
    }
    
    return result;
}

int main() {
    // Test cases
    int nums1[] = {1, 3, 0, 0, 2, 0, 0, 4};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %lld\n", zeroFilledSubarray(nums1, numsSize1)); // Expected: 6

    int nums2[] = {0, 0, 0, 2, 0, 0};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %lld\n", zeroFilledSubarray(nums2, numsSize2)); // Expected: 9

    int nums3[] = {2, 10, 2019};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %lld\n", zeroFilledSubarray(nums3, numsSize3)); // Expected: 0

    return 0;
}