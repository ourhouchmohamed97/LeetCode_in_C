// Power of Three [streak]

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

int main() {
    // Test case 1: 27 is a power of three (3^3)
    int n1 = 27;
    printf("%d is a power of three: %s\n", n1, isPowerOfThree(n1) ? "true" : "false");

    // Test case 2: 0 is not a power of three
    int n2 = 0;
    printf("%d is a power of three: %s\n", n2, isPowerOfThree(n2) ? "true" : "false");

    // Test case 3: -1 is not a power of three
    int n3 = -1;
    printf("%d is a power of three: %s\n", n3, isPowerOfThree(n3) ? "true" : "false");

    // Test case 4: 1 is a power of three (3^0)
    int n4 = 1;
    printf("%d is a power of three: %s\n", n4, isPowerOfThree(n4) ? "true" : "false");

    // Test case 5: 9 is a power of three (3^2)
    int n5 = 9;
    printf("%d is a power of three: %s\n", n5, isPowerOfThree(n5) ? "true" : "false");

    // Test case 6: 10 is not a power of three
    int n6 = 10;
    printf("%d is a power of three: %s\n", n6, isPowerOfThree(n6) ? "true" : "false");

    return 0;
}