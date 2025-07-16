// Find the Maximum Length of Valid Subsequence I

int maximumLength(int* nums, int numsSize) {
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    int maxSameParity = (evenCount > oddCount) ? evenCount : oddCount;
    int maxAlt1 = 0;
    int maxAlt2 = 0;
    int altEven = 0;
    int altOdd = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 2 == 0) {
            altEven = altOdd + 1;
        } else {
            altOdd = altEven + 1;
        }
    }

    int maxAlternating = (altEven > altOdd) ? altEven : altOdd;
    
    return (maxSameParity > maxAlternating) ? maxSameParity : maxAlternating;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: %d\n", maximumLength(nums1, numsSize1));  // Expected output: 4

    int nums2[] = {1, 2, 1, 1, 2, 1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: %d\n", maximumLength(nums2, numsSize2));  // Expected output: 6

    int nums3[] = {1, 3};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: %d\n", maximumLength(nums3, numsSize3));  // Expected output: 2

    int nums4[] = {2, 4, 6, 8};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test case 4: %d\n", maximumLength(nums4, numsSize4));  // Expected output: 4

    int nums5[] = {1, 3, 5, 7};
    int numsSize5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test case 5: %d\n", maximumLength(nums5, numsSize5));  // Expected output: 4

    return 0;
}