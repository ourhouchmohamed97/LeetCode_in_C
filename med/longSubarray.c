// Longest Subarray of 1's After Deleting One Element

#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int* nums, int numsSize) {
    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;
    
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        int currLen = right - left;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }
    return maxLen;
}

int main() {
    int nums1[] = {1,1,0,1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", longestSubarray(nums1, size1));

    int nums2[] = {0,1,1,1,0,1,1,0,1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", longestSubarray(nums2, size2));

    int nums3[] = {1,1,1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", longestSubarray(nums3, size3));

    return 0;
}