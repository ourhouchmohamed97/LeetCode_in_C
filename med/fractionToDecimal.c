// Fraction to Recurring Decimal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    long long rem;
    int index;
} Entry;

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        char* res = malloc(2);
        strcpy(res, "0");
        return res;
    }
    char* result = malloc(10050);
    int index = 0;
    if ((numerator < 0) ^ (denominator < 0)) {
        result[index++] = '-';
    }
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);
    index += sprintf(result + index, "%lld", num / den);
    num %= den;
    if (num == 0) {
        result[index] = '\0';
        return result;
    }
    result[index++] = '.';
    Entry seen[10050];
    int seenCount = 0;
    while (num != 0) {
        for (int i = 0; i < seenCount; i++) {
            if (seen[i].rem == num) {
                int repeatPos = seen[i].index;
                memmove(result + repeatPos + 1, result + repeatPos, index - repeatPos + 1);
                result[repeatPos] = '(';
                index++;
                result[index++] = ')';
                result[index] = '\0';
                return result;
            }
        }
        seen[seenCount].rem = num;
        seen[seenCount].index = index;
        seenCount++;
        num *= 10;
        result[index++] = '0' + (num / den);
        num %= den;
    }
    result[index] = '\0';
    return result;
}

int main() {
    int numerator, denominator;
    scanf("%d %d", &numerator, &denominator);
    char* res = fractionToDecimal(numerator, denominator);
    printf("%s\n", res);
    free(res);
    return 0;
}
