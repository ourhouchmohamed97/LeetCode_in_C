// Minimum Removals to Balance Array

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int maxLen = 0;
    
    for (int j = 0; j < numsSize; j++) {
        while ((long long)nums[j] > (long long)nums[i] * k) {
            i++;
        }
        int currentLen = j - i + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    
    return numsSize - maxLen;
}