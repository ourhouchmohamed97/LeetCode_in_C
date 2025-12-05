// Count Partitions with Even Sum Difference

int countPartitions(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    
    long long total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    
    return (total % 2 == 0) ? numsSize - 1 : 0;
}