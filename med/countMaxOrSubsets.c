// Count Number of Maximum Bitwise-OR Subsets

#include <stdio.h>

int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOr = 0;
    // Calculate the maximum OR which is the OR of all elements
    for (int i = 0; i < numsSize; i++) {
        maxOr |= nums[i];
    }
    
    int count = 0;
    // Iterate over all possible non-empty subsets
    for (int mask = 1; mask < (1 << numsSize); mask++) {
        int currentOr = 0;
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) {
                currentOr |= nums[i];
            }
        }
        if (currentOr == maxOr) {
            count++;
        }
    }
    return count;
}

int main() {
    // Test Case 1
    int nums1[] = {3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: %d\n", countMaxOrSubsets(nums1, numsSize1)); // Expected output: 2

    // Test Case 2
    int nums2[] = {2, 2, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2: %d\n", countMaxOrSubsets(nums2, numsSize2)); // Expected output: 7

    // Test Case 3
    int nums3[] = {3, 2, 1, 5};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: %d\n", countMaxOrSubsets(nums3, numsSize3)); // Expected output: 6

    // Additional Test Case
    int nums4[] = {1, 2, 3};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test Case 4: %d\n", countMaxOrSubsets(nums4, numsSize4)); // Expected output: 4

    return 0;
}