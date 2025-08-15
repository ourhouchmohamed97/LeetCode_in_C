// Power of Four (streak)

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if(n <= 0)
        return false;
    while(n % 4 == 0)
        n /= 4;
    return n == 1;
}

int main() {
    // Test cases
    printf("Test Case 1: %s\n", isPowerOfFour(16) ? "true" : "false"); // Expected: true
    printf("Test Case 2: %s\n", isPowerOfFour(5) ? "true" : "false");  // Expected: false
    printf("Test Case 3: %s\n", isPowerOfFour(1) ? "true" : "false");  // Expected: true
    printf("Test Case 4: %s\n", isPowerOfFour(0) ? "true" : "false");  // Expected: false
    printf("Test Case 5: %s\n", isPowerOfFour(-16) ? "true" : "false"); // Expected: false
    printf("Test Case 6: %s\n", isPowerOfFour(64) ? "true" : "false");  // Expected: true
    return 0;
}