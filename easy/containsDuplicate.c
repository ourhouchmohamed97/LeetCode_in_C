// Contains Duplicate

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    bool result = containsDuplicate(nums, numsSize);
    if (result) {
        printf("Contains duplicate\n");
    } else {
        printf("No duplicates found\n");
    }
    return 0;
}