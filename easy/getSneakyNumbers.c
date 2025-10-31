// The Two Sneaky Numbers of Digitville

#include <stdlib.h>
#include <stdio.h>

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(numsSize * sizeof(int));
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                int found = 0;
                for (int x = 0; x < k; x++) {
                    if (res[x] == nums[i]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    res[k++] = nums[i];
                }
                break;
            }
        }
    }

    *returnSize = k;
    return res;
}


int main()
{
    int nums[] = {1, 3, 2, 3, 4, 1};
    int returnSize;
    int* result = getSneakyNumbers(nums, 6, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}