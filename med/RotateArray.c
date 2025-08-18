// Rotate Array

#include <stdio.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) return;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    rotate(nums1, 7, k1);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    int nums2[] = {-1, -100, 3, 99};
    int k2 = 2;
    rotate(nums2, 4, k2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}