// Left and Right Sum Differences

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int prefix = 0;
    int suffix = 0;
    for (int i = 0; i < numsSize; i++) {
        suffix += nums[i];
    }
    int* res = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i];
        res[i] = abs(prefix - suffix);
        suffix -= nums[i];
    }
    *returnSize = numsSize;
    return res;
}