// Base 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* convertToBase7(int num) {
    if (num == 0) {
        char* result = malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    int isNegative = num < 0;
    num = abs(num);
    
    int maxDigits = 0;
    int temp = num;
    while (temp > 0) {
        temp /= 7;
        maxDigits++;
    }
    
    char* result = malloc((maxDigits + isNegative + 1) * sizeof(char));
    int index = 0;
    
    if (isNegative) {
        result[index++] = '-';
    }
    
    int start = index;
    
    while (num > 0) {
        result[index++] = '0' + (num % 7);
        num /= 7;
    }
    
    result[index] = '\0';
    
    int end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    
    return result;
}

int main() {
    int test_cases[] = {100, -7, 0, 7, 49, -49};
    int num_cases = sizeof(test_cases)/sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; i++) {
        char* result = convertToBase7(test_cases[i]);
        printf("Input: %d\nOutput: \"%s\"\n\n", test_cases[i], result);
        free(result);
    }
    
    return 0;
}