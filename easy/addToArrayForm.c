// Add to Array-Form of Integer

#include <stdio.h>
#include <stdlib.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int temp = k, kDigits = 0;
    if (temp == 0) kDigits = 1;
    while (temp > 0) {
        kDigits++;
        temp /= 10;
    }
    
    int maxSize = (numSize > kDigits ? numSize : kDigits) + 1;
    int* result = malloc(maxSize * sizeof(int));
    int idx = 0;
    int carry = 0;
    
    for (int i = numSize - 1; i >= 0 || k > 0 || carry > 0; i--) {
        int digit = carry;
        if (i >= 0) digit += num[i];
        if (k > 0) {
            digit += k % 10;
            k /= 10;
        }
        carry = digit / 10;
        result[idx++] = digit % 10;
    }
    
    *returnSize = idx;
    for (int i = 0; i < idx / 2; i++) {
        int temp = result[i];
        result[i] = result[idx - 1 - i];
        result[idx - 1 - i] = temp;
    }
    return result;
}

int main() {
    int num[] = {2,7,4};
    int numSize = 3;
    int k = 181;
    int returnSize;
    
    int* result = addToArrayForm(num, numSize, k, &returnSize);
    
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");
    
    free(result);
    return 0;
}
