// Count Numbers with Unique Digits

#include <stdio.h>

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;

    int ans = 10;
    int unique = 9;
    int available = 9;

    for (int i = 2; i <= n && available > 0; i++) {
        unique = unique * available;
        ans += unique;
        available--;
    }
    return ans;
}

int main(void) {
    int n1 = 2;
    int n2 = 0;

    printf("n = %d -> %d\n", n1, countNumbersWithUniqueDigits(n1));
    printf("n = %d -> %d\n", n2, countNumbersWithUniqueDigits(n2));

    return 0;
}
