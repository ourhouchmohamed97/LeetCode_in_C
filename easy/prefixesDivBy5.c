// Binary Prefix Divisible By 5

#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool *answer = (bool *)malloc(sizeof(bool) * numsSize);
    *returnSize = numsSize;

    int remainder = 0;
    for(int i = 0; i < numsSize; i++)
    {
        remainder = (remainder * 2 + nums[i]) %5;

        answer[i] = (remainder == 0);
    }

    return answer;
}