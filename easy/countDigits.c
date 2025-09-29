// Count the Digits That Divide a Number

#include <stdio.h>

int countDigits(int num) {
    int original = num;
    int count = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && original % digit == 0) {
            count++;
        }
        num /= 10;
    }
    
    return count;
}

int main() {
    int test_cases[] = {7, 121, 1248, 1012};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < n; i++) {
        printf("countDigits(%d) = %d\n", test_cases[i], countDigits(test_cases[i]));
    }
    
    return 0;
}