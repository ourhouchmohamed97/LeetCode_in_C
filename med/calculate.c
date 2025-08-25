// Basic Calculator II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(char* s) {
    int length = strlen(s);
    int currentNumber = 0;
    int lastNumber = 0;
    int result = 0;
    char operation = '+';
    
    for (int i = 0; i < length; i++) {
        char currentChar = s[i];
        if (isdigit(currentChar)) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !isspace(currentChar) || i == length - 1) {
            if (operation == '+' || operation == '-') {
                result += lastNumber;
                lastNumber = (operation == '+') ? currentNumber : -currentNumber;
            } else if (operation == '*') {
                lastNumber = lastNumber * currentNumber;
            } else if (operation == '/') {
                lastNumber = lastNumber / currentNumber;
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    result += lastNumber;
    return result;
}

int main() {
    char s1[] = "3+2*2";
    int result1 = calculate(s1);
    printf("Input: s = \"%s\"\n", s1);
    printf("Output: %d\n", result1);

    char s2[] = " 3/2 ";
    int result2 = calculate(s2);
    printf("Input: s = \"%s\"\n", s2);
    printf("Output: %d\n", result2);

    char s3[] = " 3+5 / 2 ";
    int result3 = calculate(s3);
    printf("Input: s = \"%s\"\n", s3);
    printf("Output: %d\n", result3);

    return 0;
}