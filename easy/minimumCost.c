// Divide an Array Into Subarrays With Minimum Cost I

#include <limits.h>

int minimumCost(int* nums, int numsSize) {
    int x1 = INT_MAX, x2 = INT_MAX;
    for (int i = 1; i < numsSize; i++){
        int x = nums[i];
        if (x < x1){
            x2 = x1;
            x1 = x;
        } else if (x < x2){
            x2 = x;
        }
    }
    return nums[0] + x1 + x2;
}