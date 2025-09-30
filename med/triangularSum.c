// Find Triangular Sum of an Array

#include <stdio.h>

int triangularSum(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    
    for (int i = 0; i < numsSize - 1; i++) {
        nums[i] = (nums[i] + nums[i + 1]) % 10;
    }
    
    return triangularSum(nums, numsSize - 1);
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Triangular sum of [1,2,3,4,5] = %d\n", triangularSum(nums1, size1));

    int nums2[] = {5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Triangular sum of [5] = %d\n", triangularSum(nums2, size2));

    int nums3[] = {9, 1, 9};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Triangular sum of [9,1,9] = %d\n", triangularSum(nums3, size3));

    return 0;
}
