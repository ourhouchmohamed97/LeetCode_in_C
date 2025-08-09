// Arranging Coins

#include <stdio.h>

int arrangeCoins(int n) {
    int count = 0;
    int row = 1;  // Start from the first row
    while (n >= row) {
        n -= row;
        row++;
        count++;
    }
    return count;
}

int main() {
    // Test cases
    int test1 = 5;
    printf("Input: %d\nOutput: %d\n", test1, arrangeCoins(test1));  // Expected: 2

    int test2 = 8;
    printf("Input: %d\nOutput: %d\n", test2, arrangeCoins(test2));  // Expected: 3

    int test3 = 1;
    printf("Input: %d\nOutput: %d\n", test3, arrangeCoins(test3));  // Expected: 1

    int test4 = 10;
    printf("Input: %d\nOutput: %d\n", test4, arrangeCoins(test4));  // Expected: 4

    return 0;
}