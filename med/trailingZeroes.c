// Factorial Trailing Zeroes

#include <stdio.h>

int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    printf("%d\n", trailingZeroes(3));
    printf("%d\n", trailingZeroes(5));
    printf("%d\n", trailingZeroes(0));
    return 0;
}