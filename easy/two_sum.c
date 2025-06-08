#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    #define HASH_SIZE 100000
    int* hash = (int*)malloc(sizeof(int) * HASH_SIZE);
    for (int i = 0; i < HASH_SIZE; i++) {
        hash[i] = -1;
    }
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hashIndex = (complement % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        
        if (hash[hashIndex] != -1) {
            result[0] = hash[hashIndex];
            result[1] = i;
            free(hash);
            return result;
        }
        
        hashIndex = (nums[i] % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        hash[hashIndex] = i;
    }
    
    free(hash);
    return result;
}

int main() 
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    
    int* indices = twoSum(nums, numsSize, target, &returnSize);
    
    if (returnSize == 2) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
    } else {
        printf("No solution found.\n");
    }
    
    free(indices);
    return 0;
}