// Convert Integer to the Sum of Two No-Zero Integers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNoZero(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    for (int a = 1; a < n; a++) {
        int b = n - a;
        if (isNoZero(a) && isNoZero(b))
        {
            result[0] = a;
            result[1] = b;
            break;
        }
    }
    return result;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int returnSize;
    int* result = getNoZeroIntegers(n, &returnSize);
    
    printf("Output: [%d, %d]\n", result[0], result[1]);
    
    free(result);
    return 0;
}