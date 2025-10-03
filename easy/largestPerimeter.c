// Largest Perimeter Triangle


#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = numsSize - 1; i >= 2; i--) {
        if (nums[i-2] + nums[i-1] > nums[i]) {
            return nums[i-2] + nums[i-1] + nums[i];
        }
    }
    return 0;
}

int main() {
    int nums1[] = {2,1,2};
    int size1 = 3;
    printf("%d\n", largestPerimeter(nums1, size1)); // Output: 5

    int nums2[] = {1,2,1,10};
    int size2 = 4;
    printf("%d\n", largestPerimeter(nums2, size2)); // Output: 0

    return 0;
}