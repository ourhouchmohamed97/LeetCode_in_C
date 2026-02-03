// Trionic Array I

#include <stdbool.h>

bool isTrionic(int* nums, int numsSize) {
    int i = 0;
    while (i + 1 < numsSize && nums[i] < nums[i + 1]) i++;
    if (i == 0 || i == numsSize - 1) return false;

    int p = i;
    while (i + 1 < numsSize && nums[i] > nums[i + 1]) i++;
    if (i == p || i == numsSize - 1) return false;

    while (i + 1 < numsSize && nums[i] < nums[i + 1]) i++;
    return i == numsSize - 1;
}