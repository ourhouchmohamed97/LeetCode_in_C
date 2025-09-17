// Sum of All Subset XOR Totals

#include <stdio.h>

int subsetXORSum(int* nums, int numsSize) {
    int orSum = 0;
    for (int i = 0; i < numsSize; i++) {
        orSum |= nums[i];
    }
    return orSum * (1 << (numsSize - 1));
}

int main() {
    int nums1[] = {1, 3};
    printf("%d\n", subsetXORSum(nums1, 2));

    int nums2[] = {5, 1, 6};
    printf("%d\n", subsetXORSum(nums2, 3));

    int nums3[] = {3, 4, 5, 6, 7, 8};
    printf("%d\n", subsetXORSum(nums3, 6));

    return 0;
}
