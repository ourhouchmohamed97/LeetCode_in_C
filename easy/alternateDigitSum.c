// Alternating Digit Sum

#include <stdio.h>

int alternateDigitSum(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int sum = 0;
    for (int i = 0; s[i]; i++) {
        int d = s[i] - '0';
        if (i % 2 == 0) sum += d;
        else sum -= d;
    }
    return sum;
}

int main() {
    printf("%d\n", alternateDigitSum(521));     // 4
    printf("%d\n", alternateDigitSum(111));     // 1
    printf("%d\n", alternateDigitSum(886996));  // 0
    return 0;
}
