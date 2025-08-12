// Fibonacci Number

#include <stdio.h>

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = fib(n);
    printf("Fibonacci of %d is %d\n", n, result);
    return 0;
}