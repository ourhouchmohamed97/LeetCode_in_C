// Number of Good Pairs

#include <stdio.h>

int numIdenticalPairs(int* nums, int numsSize) {
    int freq[101] = {0}; // since constraints: 1 <= nums[i] <= 100
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        if (freq[i] > 1) {
            count += (freq[i] * (freq[i] - 1)) / 2;
        }
    }
    return count;
}

int main() {
    int nums1[] = {1,2,3,1,1,3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", numIdenticalPairs(nums1, numsSize1)); // Expected 4

    int nums2[] = {1,1,1,1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", numIdenticalPairs(nums2, numsSize2)); // Expected 6

    int nums3[] = {1,2,3};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", numIdenticalPairs(nums3, numsSize3)); // Expected 0

    return 0;
}
