// Reordered Power of 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void countDigits(int num, int* count) {
    memset(count, 0, 10 * sizeof(int));
    if (num == 0) {
        count[0]++;
        return;
    }
    while (num > 0) {
        int digit = num % 10;
        count[digit]++;
        num /= 10;
    }
}

bool reorderedPowerOf2(int n) {
    int originalDigits[10] = {0};
    countDigits(n, originalDigits);
    for (int i = 0; i < 31; ++i) {
        int power = 1 << i;
        int powerDigits[10] = {0};
        countDigits(power, powerDigits);
        bool match = true;
        for (int j = 0; j < 10; ++j) {
            if (originalDigits[j] != powerDigits[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    if (reorderedPowerOf2(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}