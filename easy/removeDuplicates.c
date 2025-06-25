// Remove Duplicates from Sorted Array

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int k = 1; // At least one unique element (the first one)
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}

int main(){
    int nums[] = {1, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int newSize = removeDuplicates(nums, size);
    
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    
    return 0;
}