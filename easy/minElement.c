Minimum Element After Replacement With Digit Sum

#include <limits.h>

int minElement(int* nums, int numsSize) {
    int min_val = INT_MAX;

    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];
        int current_sum = 0;

        while (num > 0) {
            current_sum += num % 10;
            num /= 10;
        }

        if (current_sum < min_val)
            min_val = current_sum;
    }
    return min_val;
}
