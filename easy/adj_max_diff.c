// Maximum Difference Between Adjacent Elements in a Circular Array

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxAdjacentDistance(int* nums, int numsSize) {
    int *diff = (int *)malloc(sizeof(int) * numsSize);
    int maxDiff = 0;
    int i = 0;
    while(i < numsSize)
    {
        diff[i] = abs(nums[i] - nums[(i + 1) % numsSize]);
        i++;
    }
    i = 0;
    while(i < numsSize)
    {
        if(diff[i] > maxDiff)
            maxDiff = diff[i];
        i++;
    }
    return maxDiff;
}

int main()
{
    int nums[] = {-5, -10, -5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxAdjacentDistance(nums, numsSize);
    printf("Maximum difference between adjacent elements: %d\n", result);
    return 0;
}