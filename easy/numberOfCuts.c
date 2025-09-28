// Minimum Cuts to Divide a Circle

#include <stdio.h>

int numberOfCuts(int n) {
    if (n == 1) {
        return 0;
    } else if (n % 2 == 0) {
        return n / 2;
    } else {
        return n;
    }
}

int main() {
    int n;

    // Example 1
    n = 4;
    printf("Input: %d -> Output: %d\n", n, numberOfCuts(n)); // Expected: 2

    // Example 2
    n = 3;
    printf("Input: %d -> Output: %d\n", n, numberOfCuts(n)); // Expected: 3

    // Example 3
    n = 1;
    printf("Input: %d -> Output: %d\n", n, numberOfCuts(n)); // Expected: 0

    // Example 4
    n = 6;
    printf("Input: %d -> Output: %d\n", n, numberOfCuts(n)); // Expected: 3

    return 0;
}