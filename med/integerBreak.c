// Integer Break

#include <stdio.h>

// Function to maximize product by breaking integer n
int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;

    int product = 1;
    while (n > 4) {
        product *= 3;
        n -= 3;
    }
    return product * n;
}

int main() {
    // Test cases
    int n1 = 2;
    int n2 = 10;

    printf("Input: %d, Output: %d\n", n1, integerBreak(n1)); // Expected 1
    printf("Input: %d, Output: %d\n", n2, integerBreak(n2)); // Expected 36

    // You can test with other values
    int n3 = 8;
    printf("Input: %d, Output: %d\n", n3, integerBreak(n3)); // Expected 18 (3+3+2)

    return 0;
}
