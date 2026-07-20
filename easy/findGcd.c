// Find GCD 

int findGCD(int* nums, int numsSize) {
    int minNum = nums[0];
    int maxNum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minNum) {
            minNum = nums[i];
        }
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }

    while (maxNum != 0) {
        int temp = maxNum;
        maxNum = minNum % maxNum;
        minNum = temp;
    }

    return minNum;
}