// Maximum Difference Between Increasing Elements

#include <stdio.h>

int maximumDifference(int* nums, int numsSize) {
    if (numsSize < 2) {
        return -1;
    }
    
    int min_so_far = nums[0];
    int max_diff = -1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > min_so_far) {
            int current_diff = nums[i] - min_so_far;
            if (current_diff > max_diff) {
                max_diff = current_diff;
            }
        } else {
            min_so_far = nums[i];
        }
    }
    
    return max_diff;
}

int main()
{
    // Example usage
    int nums[] = {7, 1, 5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maximumDifference(nums, size);
    printf("Maximum difference: %d\n", result); // Output: 6
    return 0;
}
