// Smallest Number With All Set Bits

#include <stdio.h>

int smallestNumber(int n) {
    unsigned int p = 1;
    while ((int)(p - 1) < n) p <<= 1;
    return (int)(p - 1);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d\n", smallestNumber(n));
    return 0;
}
