// Pow(x, n)

#include <stdio.h>
#include <limits.h>

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}

int main() {
    double x;
    int n;

    x = 2.0;
    n = 10;
    printf("%.5f\n", myPow(x, n));

    x = 2.1;
    n = 3;
    printf("%.5f\n", myPow(x, n));

    x = 2.0;
    n = -2;
    printf("%.5f\n", myPow(x, n));

    x = 1.0;
    n = INT_MIN;
    printf("%.5f\n", myPow(x, n));

    return 0;
}