// 4Sum

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxCombinations = numsSize * (numsSize-1) * (numsSize-2) * (numsSize-3) / 24;
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        for (int j = i+1; j < numsSize - 2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            
            int left = j + 1;
            int right = numsSize - 1;
            long long currentTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            
            while (left < right) {
                long long sum = (long long)nums[left] + (long long)nums[right];
                
                if (sum == currentTarget) {
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } 
                else if (sum < currentTarget) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
    }
    
    return result;
}

void printResults(int** result, int returnSize, int* returnColumnSizes) {
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int nums[] = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    int returnSize;
    int* returnColumnSizes;
    int** result = fourSum(nums, 4, target, &returnSize, &returnColumnSizes);
    printResults(result, returnSize, returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);
    
    return 0;
}