// N-th Tribonacci Number

#include <stdio.h>

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    int a = 0, b = 1, c = 1;
    int result;
    for (int i = 3; i <= n; i++) {
        result = a + b + c;
        a = b;
        b = c;
        c = result;
    }
    return result;
}

int main() {
    int n = 25;
    printf("T(%d) = %d\n", n, tribonacci(n));
    return 0;
}