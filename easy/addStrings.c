// Add Strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    char* result = (char*)malloc(sizeof(char) * (maxLen + 2)); // +1 for carry, +1 for null terminator
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k++] = (sum % 10) + '0';
    }
    result[k] = '\0';
    
    // Reverse the result string
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    
    return result;
}

int main() {
    char num1[100], num2[100];
    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);
    
    char* result = addStrings(num1, num2);
    printf("The sum is: %s\n", result);
    
    free(result); // Don't forget to free the allocated memory
    return 0;
}