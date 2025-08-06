// Gray Code

#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    if (n == 0) {
        result[0] = 0;
        return result;
    }
    if (n == 1) {
        result[0] = 0;
        result[1] = 1;
        return result;
    }
    int prevSize;
    int* prevGray = grayCode(n - 1, &prevSize);
    for (int i = 0; i < prevSize; i++) {
        result[i] = prevGray[i];
    }
    for (int i = 0; i < prevSize; i++) {
        result[prevSize + i] = prevGray[prevSize - 1 - i] | (1 << (n - 1));
    }
    free(prevGray);
    return result;
}

int main() {
    int n = 2;
    int returnSize;
    int* result = grayCode(n, &returnSize);
    printf("Gray code sequence for n = %d:\n", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}