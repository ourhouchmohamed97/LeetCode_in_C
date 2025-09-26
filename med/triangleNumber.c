// Valid Triangle Number

#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    
    for (int k = numsSize - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    int nums1[] = {2, 2, 3, 4};
    printf("%d\n", triangleNumber(nums1, 4)); // Output: 3

    int nums2[] = {4, 2, 3, 4};
    printf("%d\n", triangleNumber(nums2, 4)); // Output: 4
}
