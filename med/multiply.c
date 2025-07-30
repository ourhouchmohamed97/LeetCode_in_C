// Multiply Strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (num1 == NULL || num2 == NULL) return NULL;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) return strdup("0");
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return strdup("0");
    
    int totalLen = len1 + len2;
    int* result = (int*)calloc(totalLen, sizeof(int));
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    int start = 0;
    while (start < totalLen && result[start] == 0) {
        start++;
    }
    
    if (start == totalLen) {
        free(result);
        return strdup("0");
    }
    
    char* resStr = (char*)malloc((totalLen - start + 1) * sizeof(char));
    int idx = 0;
    for (int i = start; i < totalLen; i++) {
        resStr[idx++] = result[i] + '0';
    }
    resStr[idx] = '\0';
    
    free(result);
    return resStr;
}

int main() {
    // Test Case 1: Single-digit multiplication
    char* num1 = "2";
    char* num2 = "3";
    char* result = multiply(num1, num2);
    printf("Test Case 1: %s * %s = %s\n", num1, num2, result);
    free(result);

    // Test Case 2: Multi-digit multiplication
    num1 = "123";
    num2 = "456";
    result = multiply(num1, num2);
    printf("Test Case 2: %s * %s = %s\n", num1, num2, result);
    free(result);

    // Test Case 3: Multiplication involving zero
    num1 = "0";
    num2 = "12345";
    result = multiply(num1, num2);
    printf("Test Case 3: %s * %s = %s\n", num1, num2, result);
    free(result);

    // Test Case 4: Large numbers
    num1 = "999999999";
    num2 = "999999999";
    result = multiply(num1, num2);
    printf("Test Case 4: %s * %s = %s\n", num1, num2, result);
    free(result);

    // Test Case 5: One number is "1"
    num1 = "1";
    num2 = "987654321";
    result = multiply(num1, num2);
    printf("Test Case 5: %s * %s = %s\n", num1, num2, result);
    free(result);

    return 0;
}