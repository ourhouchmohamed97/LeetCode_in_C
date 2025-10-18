// Maximum Number of Distinct Elements After Operations

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    int lastUsed = -1000000000;
    for (int i = 0; i < numsSize; i++) {
        int start = nums[i] - k;
        int end = nums[i] + k;
        if (start <= lastUsed)
            start = lastUsed + 1;
        if (start <= end) {
            count++;
            lastUsed = start;
        }
    }
    return count;
}

int main() {
    int nums1[] = {1, 2, 2, 3, 3, 4};
    printf("%d\n", maxDistinctElements(nums1, 6, 2));

    int nums2[] = {4, 4, 4, 4};
    printf("%d\n", maxDistinctElements(nums2, 4, 1));

    return 0;
}
