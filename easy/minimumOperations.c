// Find Minimum Operations to Make All Elements Divisible by Three

int minimumOperations(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int remainder = nums[i] % 3;
        if (remainder != 0) {
            count += (remainder == 1) ? 1 : 1;
        }
    }
    return count;
}