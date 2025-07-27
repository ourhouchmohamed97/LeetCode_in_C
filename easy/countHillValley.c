// Count Hills and Valleys in an Array

#include <stdio.h>

int countHillValley(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    int processed[numsSize];
    int processedSize = 0;
    
    processed[processedSize++] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            processed[processedSize++] = nums[i];
        }
    }
    
    int count = 0;
    for (int i = 1; i < processedSize - 1; i++) {
        int left = processed[i-1];
        int current = processed[i];
        int right = processed[i+1];
        
        if ((current > left && current > right) || (current < left && current < right)) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Test case 1: Example from the problem statement
    int nums1[] = {2, 4, 1, 1, 6, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: [2, 4, 1, 1, 6, 5]\n");
    printf("Expected output: 3\n");
    printf("Actual output: %d\n\n", countHillValley(nums1, numsSize1));

    // Test case 2: Another example from the problem statement
    int nums2[] = {6, 6, 5, 5, 4, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: [6, 6, 5, 5, 4, 1]\n");
    printf("Expected output: 0\n");
    printf("Actual output: %d\n\n", countHillValley(nums2, numsSize2));

    // Test case 3: All elements the same
    int nums3[] = {3, 3, 3, 3, 3};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: [3, 3, 3, 3, 3]\n");
    printf("Expected output: 0\n");
    printf("Actual output: %d\n\n", countHillValley(nums3, numsSize3));

    // Test case 4: Small array with no hills or valleys
    int nums4[] = {1, 2};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test case 4: [1, 2]\n");
    printf("Expected output: 0\n");
    printf("Actual output: %d\n\n", countHillValley(nums4, numsSize4));

    // Test case 5: Array with alternating hills and valleys
    int nums5[] = {1, 3, 2, 4, 3, 5, 4};
    int numsSize5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test case 5: [1, 3, 2, 4, 3, 5, 4]\n");
    printf("Expected output: 4\n");
    printf("Actual output: %d\n\n", countHillValley(nums5, numsSize5));

    return 0;
}