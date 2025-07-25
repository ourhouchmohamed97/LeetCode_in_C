// Maximum Unique Subarray Sum After Deletion

#include <stdio.h>
#include <stdlib.h>

int maxSum(int* nums, int numsSize) {
    int res = 0;
    int* hash = (int*)calloc(sizeof(int), 202);
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] + 100]++;
    }
    for (int i = 100; i < 202; i++) {
        if (hash[i] > 0) {
            res += i - 100;
        }
    }
    if (res == 0) {
        for (int i = 0; i <= 100; i++) {
            if (hash[i] > 0) {
                res = i - 100;
                break;
            }
        }
    }
    free(hash);
    return res;
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: %d\n", maxSum(nums1, size1)); // Expected: 15

    int nums2[] = {1, 1, 0, 1, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2: %d\n", maxSum(nums2, size2)); // Expected: 1

    int nums3[] = {-100};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: %d\n", maxSum(nums3, size3)); // Expected: -100

    int nums4[] = {-20, 20};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test Case 4: %d\n", maxSum(nums4, size4)); // Expected: 20

    int nums5[] = {-4, 9, 2};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test Case 5: %d\n", maxSum(nums5, size5)); // Expected: 11

    return 0;
}