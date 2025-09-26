// Smallest Even Multiple

#include <stdio.h>

// Your function
int smallestEvenMultiple(int n) {
    if (n % 2 == 0)
        return n;
    return 2 * n;
}

int main() {
    int n1 = 5;
    int n2 = 6;

    printf("Input: %d -> Output: %d\n", n1, smallestEvenMultiple(n1)); // 10
    printf("Input: %d -> Output: %d\n", n2, smallestEvenMultiple(n2)); // 6

    return 0;
}
