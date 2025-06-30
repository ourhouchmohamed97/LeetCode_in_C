// Longest Harmonious Subsequence
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

≈
int main() {
    int nums1[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%d\n", findLHS(nums1, numsSize1)); // Output: 5
    
    int nums2[] = {1, 2, 3, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d\n", findLHS(nums2, numsSize2)); // Output: 2
    
    int nums3[] = {1, 1, 1, 1};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("%d\n", findLHS(nums3, numsSize3)); // Output: 0
    
    return 0;
}