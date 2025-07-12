// Plus One

#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        if (carry == 0)
            break;
    }

    if (carry == 1) {
        int* result = malloc((digitsSize + 1) * sizeof(int));
        result[0] = 1;
        for (int i = 0; i < digitsSize; i++) {
            result[i + 1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return result;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}

int main() {
    int digits[] = {9, 9, 9};
    int returnSize;
    int* result = plusOne(digits, 3, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Free memory only if malloc was used
    if (result != digits)
        free(result);

    return 0;
}