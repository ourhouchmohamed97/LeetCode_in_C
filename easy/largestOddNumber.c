// Largest Odd Number in String

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* largestOddNumber(char* num) {
    int n = strlen(num);
    for (int i = n - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 == 1) {
            char* res = (char*)malloc(i + 2);
            strncpy(res, num, i + 1);
            res[i + 1] = '\0';
            return res;
        }
    }
    char* empty = (char*)malloc(1);
    empty[0] = '\0';
    return empty;
}

int main() {
    char num1[] = "52";
    printf("%s\n", largestOddNumber(num1)); // 5

    char num2[] = "4206";
    printf("%s\n", largestOddNumber(num2)); // ""

    char num3[] = "35427";
    printf("%s\n", largestOddNumber(num3)); // 35427

    return 0;
}
