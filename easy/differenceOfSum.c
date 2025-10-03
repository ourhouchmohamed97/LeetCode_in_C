// Difference Between Element Sum and Digit Sum of an Array

#include <stdio.h>
#include <stdlib.h>  // for abs()

int differenceOfSum(int* nums, int numsSize) {
    int elem_sum = 0;
    int dig_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        elem_sum += nums[i];

        int n = nums[i];
        while (n > 0) {
            dig_sum += n % 10;
            n /= 10;
        }
    }

    return abs(elem_sum - dig_sum);
}

int main() {
    int nums1[] = {1, 15, 6, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", differenceOfSum(nums1, size1)); // Expected 9

    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", differenceOfSum(nums2, size2)); // Expected 0

    return 0;
}
