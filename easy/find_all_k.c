// Find All K-Distant Indices in an Array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    bool* isKDistant = (bool*)calloc(numsSize, sizeof(bool));
    if (isKDistant == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    for (int j = 0; j < numsSize; ++j) {
        if (nums[j] == key) {
            int start = (j - k) > 0 ? (j - k) : 0;
            int end = (j + k) < (numsSize - 1) ? (j + k) : (numsSize - 1);
            for (int i = start; i <= end; ++i) {
                isKDistant[i] = true;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (isKDistant[i]) {
            count++;
        }
    }
    
    int* result = (int*)malloc(count * sizeof(int));
    if (result == NULL) {
        free(isKDistant);
        *returnSize = 0;
        return NULL;
    }
    
    int index = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (isKDistant[i]) {
            result[index++] = i;
        }
    }
    
    free(isKDistant);
    *returnSize = count;
    return result;
}

// Example usage:

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int key = 3;
    int k = 1;
    int returnSize;

    int* indices = findKDistantIndices(nums, numsSize, key, k, &returnSize);
    
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", indices[i]);
    }
    
    free(indices);
    return 0;
}