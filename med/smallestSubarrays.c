// Smallest Subarrays With Maximum Bitwise OR

#include <stdio.h>
#include <stdlib.h>

int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int bit_pos[32] = {0};

    for (int i = numsSize - 1; i >= 0; i--) {
        for (int b = 0; b < 32; b++) {
            if ((nums[i] >> b) & 1) {
                bit_pos[b] = i;
            }
        }

        int max_len = i;
        for (int b = 0; b < 32; b++) {
            if (bit_pos[b] > max_len) {
                max_len = bit_pos[b];
            }
        }
        answer[i] = max_len - i + 1;
    }
    return answer;
}

int main() {
    int nums[] = {1, 0, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = smallestSubarrays(nums, numsSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
