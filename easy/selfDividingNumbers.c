// Self Dividing Numbers

#include <stdio.h>
#include <stdlib.h>

int isSelfDividing(int num) {
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || original % digit != 0) {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* result = (int*)malloc((right - left + 1) * sizeof(int));
    *returnSize = 0;
    for (int i = left; i <= right; i++) {
        if (isSelfDividing(i)) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}

// Example usage (main function for testing)
int main() {
    int left1 = 1, right1 = 22;
    int size1;
    int* result1 = selfDividingNumbers(left1, right1, &size1);
    printf("Output for [1, 22]: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int left2 = 47, right2 = 85;
    int size2;
    int* result2 = selfDividingNumbers(left2, right2, &size2);
    printf("Output for [47, 85]: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    return 0;
}