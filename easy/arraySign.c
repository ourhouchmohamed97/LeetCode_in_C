// Sign of the Product of an Array

#include <stdio.h>

int signFunc(int x) {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

int arraySign(int* nums, int numsSize) {
    int prod = 1;
    for (int i = 0; i < numsSize; i++)
        prod *= signFunc(nums[i]);
    return prod;
}

int main() {
    int nums1[] = {-1, -2, -3, -4, 3, 2, 1};
    int nums2[] = {1, 5, 0, 2, -3};
    int nums3[] = {-1, 1, -1, 1, -1};

    printf("Output 1: %d\n", arraySign(nums1, sizeof(nums1)/sizeof(nums1[0]))); // 1
    printf("Output 2: %d\n", arraySign(nums2, sizeof(nums2)/sizeof(nums2[0]))); // 0
    printf("Output 3: %d\n", arraySign(nums3, sizeof(nums3)/sizeof(nums3[0]))); // -1

    return 0;
}
