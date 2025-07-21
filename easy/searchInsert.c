// Search Insert Position

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int nums1[] = {1, 3, 5, 6};
    int target1 = 5;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = searchInsert(nums1, size1, target1);
    printf("Test Case 1: nums = [1,3,5,6], target = %d\n", target1);
    printf("Output: %d (Expected: 2)\n\n", result1);

    int nums2[] = {1, 3, 5, 6};
    int target2 = 2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = searchInsert(nums2, size2, target2);
    printf("Test Case 2: nums = [1,3,5,6], target = %d\n", target2);
    printf("Output: %d (Expected: 1)\n\n", result2);

    int nums3[] = {1, 3, 5, 6};
    int target3 = 7;
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int result3 = searchInsert(nums3, size3, target3);
    printf("Test Case 3: nums = [1,3,5,6], target = %d\n", target3);
    printf("Output: %d (Expected: 4)\n\n", result3);

    int nums4[] = {1, 3, 5, 6};
    int target4 = 0;
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int result4 = searchInsert(nums4, size4, target4);
    printf("Test Case 4: nums = [1,3,5,6], target = %d\n", target4);
    printf("Output: %d (Expected: 0)\n\n", result4);

    int nums5[] = {};
    int target5 = 5;
    int size5 = 0;
    int result5 = searchInsert(nums5, size5, target5);
    printf("Test Case 5: nums = [], target = %d\n", target5);
    printf("Output: %d (Expected: 0)\n\n", result5);

    return 0;
}