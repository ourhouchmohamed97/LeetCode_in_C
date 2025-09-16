// Sum of Digits in Base K

#include <stdio.h>

int sumBase(int n, int k) {
    int sum = 0;
    while (n > 0) {
        sum += n % k;
        n /= k;
    }
    return sum;
}

int main() {
    int n1 = 34, k1 = 6;
    int n2 = 10, k2 = 10;

    printf("%d\n", sumBase(n1, k1)); // 9
    printf("%d\n", sumBase(n2, k2)); // 1

    return 0;
}
