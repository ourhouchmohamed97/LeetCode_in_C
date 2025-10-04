// Split With Minimum Sum

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumSum(int num) {
    int digits[10], n = 0;
    while (num > 0) {
        digits[n++] = num % 10;
        num /= 10;
    }
    qsort(digits, n, sizeof(int), cmp);
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) num1 = num1 * 10 + digits[i];
        else num2 = num2 * 10 + digits[i];
    }
    return num1 + num2;
}

int main() {
    int num1 = 4325;
    int num2 = 687;
    printf("%d\n", minimumSum(num1));
    printf("%d\n", minimumSum(num2));
    return 0;
}
