// N-Repeated Element in Size 2N Array


int repeatedNTimes(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (i + 1 < numsSize && nums[i] == nums[i + 1])
            return nums[i];
        if (i + 2 < numsSize && nums[i] == nums[i + 2])
            return nums[i];
        if (i + 3 < numsSize && nums[i] == nums[i + 3])
            return nums[i];
    }
    return -1; // should never happen given the problem constraints
}
