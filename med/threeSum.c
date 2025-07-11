// 3Sum

#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array first
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue; // Skip duplicate elements
        }
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* returnColumnSizes1;
    int** result1 = threeSum(nums1, numsSize1, &returnSize1, &returnColumnSizes1);
    
    printf("Test Case 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d, %d]\n", result1[i][0], result1[i][1], result1[i][2]);
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);
    
    int nums2[] = {0, 1, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* returnColumnSizes2;
    int** result2 = threeSum(nums2, numsSize2, &returnSize2, &returnColumnSizes2);
    
    printf("Test Case 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("[%d, %d, %d]\n", result2[i][0], result2[i][1], result2[i][2]);
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes2);
    
    int nums3[] = {0, 0, 0};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    int* returnColumnSizes3;
    int** result3 = threeSum(nums3, numsSize3, &returnSize3, &returnColumnSizes3);
    
    printf("Test Case 3:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("[%d, %d, %d]\n", result3[i][0], result3[i][1], result3[i][2]);
        free(result3[i]);
    }
    free(result3);
    free(returnColumnSizes3);
    
    return 0;
}