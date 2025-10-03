// Count Distinct Numbers on Board

#include <stdio.h>

int distinctIntegers(int n) {
    if (n == 1) return 1;
    return n - 1;
}

int main() {
    int n1 = 5;
    int n2 = 1;
    printf("%d\n", distinctIntegers(n1));
    printf("%d\n", distinctIntegers(n2));
    return 0;
}
