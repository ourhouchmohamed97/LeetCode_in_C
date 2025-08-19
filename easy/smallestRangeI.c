// Smallest Range I

#include <stdio.h>
#include <limits.h>

int smallestRangeI(int* nums, int numsSize, int k) {
    if (numsSize == 1) return 0;
    
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) min_val = nums[i];
        if (nums[i] > max_val) max_val = nums[i];
    }
    
    int potential_min = min_val + k;
    int potential_max = max_val - k;
    
    if (potential_min >= potential_max) return 0;
    else return potential_max - potential_min;
}

int main() {
    int nums1[] = {1};
    printf("%d\n", smallestRangeI(nums1, 1, 0)); // Output: 0
    
    int nums2[] = {0, 10};
    printf("%d\n", smallestRangeI(nums2, 2, 2)); // Output: 6
    
    int nums3[] = {1, 3, 6};
    printf("%d\n", smallestRangeI(nums3, 3, 3)); // Output: 0
    
    return 0;
}