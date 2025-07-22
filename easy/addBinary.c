// Add Binary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char* result = (char*)malloc((max_len + 2) * sizeof(char)); // +1 for carry, +1 for null terminator
    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[k] = '\0';
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }

    return result;
}

int main() {
    char* a1 = "11";
    char* b1 = "1";
    char* result1 = addBinary(a1, b1);
    printf("Test Case 1: %s\n", result1); // Expected output: "100"
    free(result1);

    char* a2 = "1010";
    char* b2 = "1011";
    char* result2 = addBinary(a2, b2);
    printf("Test Case 2: %s\n", result2); // Expected output: "10101"
    free(result2);

    return 0;
}