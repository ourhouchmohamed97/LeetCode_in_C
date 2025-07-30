// Longest Subarray With Maximum Bitwise AND

#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int max_num = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
    }
    
    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == max_num) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 0;
        }
    }
    
    return max_length;
}

int main() {
    // Test Case 1
    int nums1[] = {1, 2, 3, 3, 2, 2};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = longestSubarray(nums1, numsSize1);
    printf("Test Case 1: %d\n", result1); // Expected output: 2

    // Test Case 2
    int nums2[] = {1, 2, 3, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = longestSubarray(nums2, numsSize2);
    printf("Test Case 2: %d\n", result2); // Expected output: 1

    // Test Case 3
    int nums3[] = {2, 2, 2, 2};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int result3 = longestSubarray(nums3, numsSize3);
    printf("Test Case 3: %d\n", result3); // Expected output: 4

    // Test Case 4
    int nums4[] = {5, 5, 5, 1, 5, 5};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    int result4 = longestSubarray(nums4, numsSize4);
    printf("Test Case 4: %d\n", result4); // Expected output: 3

    return 0;
}