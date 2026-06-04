// Total Waviness of Numbers in Range I

#include <stdlib.h>

int totalWaviness(int num1, int num2) {
    int total = 0;
    int digits[12];

    for (int num = num1; num <= num2; ++num) {
        if (num < 100) continue;

        int len = 0;
        int temp = num;
        while (temp > 0) {
            digits[len++] = temp % 10;
            temp /= 10;
        }
        for (int i = 1; i < len - 1; ++i) {
            if ((digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) || 
                (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])) {
                total++;
            }
        }
    }
    return total;
}