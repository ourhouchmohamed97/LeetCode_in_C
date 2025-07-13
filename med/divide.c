// Divide Two Integers

#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    
    long long ldividend = llabs((long long)dividend);
    long long ldivisor = llabs((long long)divisor);
    
    long long quotient = 0;
    
    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        quotient += multiple;
    }
    
    quotient = sign * quotient;
    
    if (quotient > INT_MAX) {
        return INT_MAX;
    }
    if (quotient < INT_MIN) {
        return INT_MIN;
    }
    
    return (int)quotient;
}

int main() {
    int dividend1 = 10;
    int divisor1 = 3;
    int result1 = divide(dividend1, divisor1);
    printf("Example 1: %d / %d = %d\n", dividend1, divisor1, result1);  // Expected output: 3
    
    int dividend2 = 7;
    int divisor2 = -3;
    int result2 = divide(dividend2, divisor2);
    printf("Example 2: %d / %d = %d\n", dividend2, divisor2, result2);  // Expected output: -2
    
    int dividend3 = INT_MIN;
    int divisor3 = -1;
    int result3 = divide(dividend3, divisor3);
    printf("Edge Case: %d / %d = %d\n", dividend3, divisor3, result3);  // Expected output: INT_MAX
    
    return 0;
}