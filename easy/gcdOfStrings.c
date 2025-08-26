// Greatest Common Divisor of Strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Check if str1 + str2 equals str2 + str1
    char* concat1 = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    char* concat2 = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    
    strcpy(concat1, str1);
    strcat(concat1, str2);
    
    strcpy(concat2, str2);
    strcat(concat2, str1);
    
    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);
        return "";
    }
    
    free(concat1);
    free(concat2);
    
    int gcd_len = gcd(len1, len2);
    char* result = (char*)malloc(sizeof(char) * (gcd_len + 1));
    strncpy(result, str1, gcd_len);
    result[gcd_len] = '\0';
    
    return result;
}

int main() {
    // Example 1
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    char* result1 = gcdOfStrings(str1, str2);
    printf("Example 1 Output: %s\n", result1); // Expected "ABC"
    free(result1);
    
    // Example 2
    char str3[] = "ABABAB";
    char str4[] = "ABAB";
    char* result2 = gcdOfStrings(str3, str4);
    printf("Example 2 Output: %s\n", result2); // Expected "AB"
    free(result2);
    
    // Example 3
    char str5[] = "LEET";
    char str6[] = "CODE";
    char* result3 = gcdOfStrings(str5, str6);
    printf("Example 3 Output: %s\n", result3); // Expected ""
    free(result3);
    
    return 0;
}