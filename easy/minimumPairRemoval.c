// Minimum Pair Removal to Sort Array I

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isNonDecreasing(int* nums, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int minimumOperations(int* nums, int numsSize) {
    int n = numsSize;
    int operations = 0;
    
    while (n > 1) {
        // Check if already non-decreasing
        if (isNonDecreasing(nums, n)) {
            break;
        }
        
        // Find adjacent pair with minimum sum (leftmost if ties)
        int minSum = INT_MAX;
        int minIndex = -1;
        
        for (int i = 0; i < n - 1; i++) {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIndex = i;
            }
        }
        
        // Replace the pair with their sum
        nums[minIndex] = minSum;
        
        // Shift elements to remove the second element of the pair
        for (int i = minIndex + 1; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }
        
        n--;  // Array effectively shorter by 1
        operations++;
    }
    
    return operations;
}

// Test function
int main() {
    // Test case 1: [5,2,3,1]
    int nums1[] = {5, 2, 3, 1};
    printf("Input: [5,2,3,1]\n");
    printf("Output: %d\n", minimumOperations(nums1, 4));
    
    // Test case 2: [1,2,2]
    int nums2[] = {1, 2, 2};
    printf("Input: [1,2,2]\n");
    printf("Output: %d\n", minimumOperations(nums2, 3));
    
    return 0;
}
