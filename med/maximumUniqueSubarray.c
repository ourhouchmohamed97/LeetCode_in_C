// Maximum Erasure Value

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumUniqueSubarray(int* nums, int numsSize) {
    int* seen = (int*)calloc(100001, sizeof(int));
    memset(seen, 0, 100001 * sizeof(int));
    int left = 0;
    int max_sum = 0;
    int current_sum = 0;
    
    for (int right = 0; right < numsSize; right++) {
        int num = nums[right];
        while (seen[num] != 0) {
            int left_num = nums[left];
            seen[left_num] = 0;
            current_sum -= left_num;
            left++;
        }
        seen[num] = 1;
        current_sum += num;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    free(seen);
    return max_sum;
}

int main() {
    int nums1[] = {4, 2, 4, 5, 6};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = maximumUniqueSubarray(nums1, numsSize1);
    printf("Test Case 1: %d\n", result1); // Expected output: 17

    int nums2[] = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = maximumUniqueSubarray(nums2, numsSize2);
    printf("Test Case 2: %d\n", result2); // Expected output: 8

    int nums3[] = {1, 2, 3, 4, 5};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int result3 = maximumUniqueSubarray(nums3, numsSize3);
    printf("Test Case 3: %d\n", result3); // Expected output: 15

    return 0;
}