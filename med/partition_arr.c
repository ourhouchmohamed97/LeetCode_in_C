// Partition Array Such That Maximum Difference Is K

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int partitionArray(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 1;
    int start = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - start > k) {
            count++;
            start = nums[i];
        }
    }
    
    return count;
}

// Test cases
int main() {
    int nums1[] = {3,6,1,2,5};
    int k1 = 2;
    printf("%d\n", minSubsequences(nums1, 5, k1)); // Output: 2
    
    int nums2[] = {1,2,3};
    int k2 = 1;
    printf("%d\n", minSubsequences(nums2, 3, k2)); // Output: 2
    
    int nums3[] = {2,2,4,5};
    int k3 = 0;
    printf("%d\n", minSubsequences(nums3, 4, k3)); // Output: 3
    
    return 0;
}
