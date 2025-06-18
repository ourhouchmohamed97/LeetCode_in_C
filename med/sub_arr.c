// Divide Array Into Arrays With Max Difference


#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int n = numsSize / 3;
    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            for (int j = 0; j < *returnSize; j++) {
                free(result[j]);
            }
            free(result);
            free(*returnColumnSizes);
            *returnSize = 0;
            return NULL;
        }
        result[*returnSize] = (int*)malloc(3 * sizeof(int));
        result[*returnSize][0] = nums[i];
        result[*returnSize][1] = nums[i + 1];
        result[*returnSize][2] = nums[i + 2];
        (*returnColumnSizes)[*returnSize] = 3;
        (*returnSize)++;
    }
    
    return result;
}

// Helper function to print the result for demonstration purposes
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    // Example 1
    int nums1[] = {1,3,4,8,7,9,3,5,1};
    int k1 = 2;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* returnColumnSizes1;
    int** result1 = divideArray(nums1, numsSize1, k1, &returnSize1, &returnColumnSizes1);
    if (returnSize1 == 0) {
        printf("[]\n");
    } else {
        printResult(result1, returnSize1, returnColumnSizes1);
        for (int i = 0; i < returnSize1; i++) {
            free(result1[i]);
        }
        free(result1);
        free(returnColumnSizes1);
    }
    
    // Example 2
    int nums2[] = {2,4,2,2,5,2};
    int k2 = 2;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* returnColumnSizes2;
    int** result2 = divideArray(nums2, numsSize2, k2, &returnSize2, &returnColumnSizes2);
    if (returnSize2 == 0) {
        printf("[]\n");
    } else {
        printResult(result2, returnSize2, returnColumnSizes2);
        for (int i = 0; i < returnSize2; i++) {
            free(result2[i]);
        }
        free(result2);
        free(returnColumnSizes2);
    }
    
    // Example 3
    int nums3[] = {4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    int k3 = 14;
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    int* returnColumnSizes3;
    int** result3 = divideArray(nums3, numsSize3, k3, &returnSize3, &returnColumnSizes3);
    if (returnSize3 == 0) {
        printf("[]\n");
    } else {
        printResult(result3, returnSize3, returnColumnSizes3);
        for (int i = 0; i < returnSize3; i++) {
            free(result3[i]);
        }
        free(result3);
        free(returnColumnSizes3);
    }
    
    return 0;
}