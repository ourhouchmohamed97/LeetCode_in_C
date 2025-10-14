//  Adjacent Increasing Subarrays Detection I

#include <stdio.h>
#include <stdbool.h>

bool isStrictlyIncreasing(int* nums, int start, int k) {
    for (int i = start + 1; i < start + k; i++) {
        if (nums[i] <= nums[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    if (numsSize < 2 * k) {
        return false;
    }
    
    for (int a = 0; a + 2 * k <= numsSize; a++) {
        int b = a + k;
        
        if (isStrictlyIncreasing(nums, a, k) && 
            isStrictlyIncreasing(nums, b, k)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int nums1[] = {2,5,7,8,9,2,3,4,3,1};
    int k1 = 3;
    printf("Example 1: %s\n", hasIncreasingSubarrays(nums1, 10, k1) ? "true" : "false");
    
    int nums2[] = {1,2,3,4,4,4,4,5,6,7};
    int k2 = 5;
    printf("Example 2: %s\n", hasIncreasingSubarrays(nums2, 10, k2) ? "true" : "false");
    
    return 0;
}
