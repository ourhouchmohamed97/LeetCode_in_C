// Remove Element

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int newSize = 0;
    while(i < numsSize)
    {
        if(nums[i] != val)
        {
            nums[newSize] = nums[i];
            newSize++;
        }
        i++;
    }
    return newSize;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;
    int newSize = removeElement(nums, numsSize, val);
    printf("New size: %d\n", newSize);
    return 0;
}