// Maximum Product of Two Elements in an Array

int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int val = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
           val = (nums[i] - 1) * (nums[j] - 1);
           if (val > max)
                max = val;
        }
    }
    return max;
}