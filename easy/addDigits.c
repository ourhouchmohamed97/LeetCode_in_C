// Add Digits

#include <stdio.h>

int addDigits(int num) {
    int div, mod;
    while(num > 9) {
        div = num / 10;
        mod = num % 10;
        num = div + mod;
    }
    return num;
}

int main() {
    int test_numbers[] = {38, 0, 23};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        int num = test_numbers[i];
        int result = addDigits(num);
        printf("addDigits(%d) = %d\n", num, result);
    }

    return 0;
}