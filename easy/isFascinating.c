// Check if The Number is Fascinating

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isFascinating(int n) {
    char str[20];
    sprintf(str, "%d%d%d", n, 2 * n, 3 * n);  // Concatenate n, 2n, 3n

    // Must have exactly 9 digits
    if (strlen(str) != 9) return false;

    int seen[10] = {0};

    for (int i = 0; i < 9; i++) {
        int digit = str[i] - '0';
        // Invalid if digit is 0 or repeated
        if (digit == 0 || seen[digit]) return false;
        seen[digit] = 1;
    }

    return true; // Passed all checks
}

int main() {
    int n1 = 192;
    int n2 = 100;

    printf("Input: %d -> %s\n", n1, isFascinating(n1) ? "true" : "false");
    printf("Input: %d -> %s\n", n2, isFascinating(n2) ? "true" : "false");

    return 0;
}
