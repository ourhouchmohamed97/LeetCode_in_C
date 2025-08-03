// Nim Game

#include <stdio.h>
#include <stdbool.h>

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    // Test cases
    printf("n = 1: %s\n", canWinNim(1) ? "true" : "false");  // Expected: true
    printf("n = 2: %s\n", canWinNim(2) ? "true" : "false");  // Expected: true
    printf("n = 3: %s\n", canWinNim(3) ? "true" : "false");  // Expected: true
    printf("n = 4: %s\n", canWinNim(4) ? "true" : "false");  // Expected: false
    printf("n = 5: %s\n", canWinNim(5) ? "true" : "false");  // Expected: true
    printf("n = 6: %s\n", canWinNim(6) ? "true" : "false");  // Expected: true
    printf("n = 7: %s\n", canWinNim(7) ? "true" : "false");  // Expected: true
    printf("n = 8: %s\n", canWinNim(8) ? "true" : "false");  // Expected: false

    return 0;
}