// Missing Number

#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int missing = numsSize;
    for (int i = 0; i < numsSize; i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}

int main() {
    // Test Case 1: Missing 2
    int nums1[] = {3, 0, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Missing number (Test 1): %d\n", missingNumber(nums1, size1)); // Output: 2

    // Test Case 2: Missing 2
    int nums2[] = {0, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Missing number (Test 2): %d\n", missingNumber(nums2, size2)); // Output: 2

    // Test Case 3: Missing 8
    int nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Missing number (Test 3): %d\n", missingNumber(nums3, size3)); // Output: 8

    // Edge Case: Empty array (n=0, missing=0)
    int nums4[] = {};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Missing number (Edge Case): %d\n", missingNumber(nums4, size4)); // Output: 0

    return 0;
}