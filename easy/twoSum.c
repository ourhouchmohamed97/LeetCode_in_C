// two sum

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
    } else {
        printf("No solution found.\n");
    }
    free(result);
    return 0;
}