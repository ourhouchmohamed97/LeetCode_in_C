// Maximum Product of Three Numbers

#include <stdio.h>
#include <limits.h>

int maximumProduct(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] > max3) {
            max3 = nums[i];
        }
        
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
    }
    
    int product1 = max1 * max2 * max3;
    int product2 = min1 * min2 * max1;
    
    return product1 > product2 ? product1 : product2;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {1, 2, 3, 4};
    int nums3[] = {-1, -2, -3};
    
    printf("%d\n", maximumProduct(nums1, 3));
    printf("%d\n", maximumProduct(nums2, 4));
    printf("%d\n", maximumProduct(nums3, 3));
    
    return 0;
}