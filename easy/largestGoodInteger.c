// Largest 3-Same-Digit Number in String

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* largestGoodInteger(char* num) {
    char* result = malloc(4 * sizeof(char));
    result[0] = '\0';
    int max_digit = -1;
    int len = strlen(num);
    
    for (int i = 0; i <= len - 3; ++i) {
        if (num[i] == num[i+1] && num[i] == num[i+2]) {
            int current_digit = num[i] - '0';
            if (current_digit > max_digit) {
                max_digit = current_digit;
                result[0] = num[i];
                result[1] = num[i];
                result[2] = num[i];
                result[3] = '\0';
            }
        }
    }
    
    if (max_digit == -1) {
        free(result);
        return strdup("");
    } else {
        return result;
    }
}

int main() {
    char num1[] = "6777133339";
    char* result1 = largestGoodInteger(num1);
    printf("Output: \"%s\"\n", result1);
    free(result1);

    char num2[] = "2300019";
    char* result2 = largestGoodInteger(num2);
    printf("Output: \"%s\"\n", result2);
    free(result2);

    char num3[] = "42352338";
    char* result3 = largestGoodInteger(num3);
    printf("Output: \"%s\"\n", result3);
    free(result3);

    return 0;
}