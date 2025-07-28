// Excel Sheet Column Number

#include <stdio.h>
#include <ctype.h>

int titleToNumber(char* columnTitle) {
    int result = 0;
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        result = result * 26 + (columnTitle[i] - 'A' + 1);
    }
    return result;
}

int main() {
    // Test Case 1
    char columnTitle1[] = "A";
    printf("Test Case 1: %d\n", titleToNumber(columnTitle1)); // Expected output: 1

    // Test Case 2
    char columnTitle2[] = "AB";
    printf("Test Case 2: %d\n", titleToNumber(columnTitle2)); // Expected output: 28

    // Test Case 3
    char columnTitle3[] = "ZY";
    printf("Test Case 3: %d\n", titleToNumber(columnTitle3)); // Expected output: 701

    // Additional Test Case
    char columnTitle4[] = "FXSHRXW";
    printf("Test Case 4: %d\n", titleToNumber(columnTitle4)); // Expected output: 2147483647

    return 0;
}