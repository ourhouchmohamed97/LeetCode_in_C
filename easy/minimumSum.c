// Minimum Sum of Four Digit Number After Splitting Digits

#include <stdio.h>

int minimumSum(int num) {
    int d[4];
    for (int i = 0; i < 4; ++i) {
        d[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (d[i] > d[j]) {
                int t = d[i];
                d[i] = d[j];
                d[j] = t;
            }
        }
    }

    int new1 = d[0] * 10 + d[2];
    int new2 = d[1] * 10 + d[3];
    return new1 + new2;
}

int main() {
    printf("%d\n", minimumSum(2932)); // 52
    printf("%d\n", minimumSum(4009)); // 13
    return 0;
}
