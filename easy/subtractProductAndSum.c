// Subtract the Product and Sum of Digits of an Integer

#include <stdio.h>

int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    
    while (n > 0) {
        int digit = n % 10;
        product *= digit;
        sum += digit;
        n /= 10;
    }
    
    return product - sum;
}

int main() {
    int n1 = 234;
    printf("Input: n = %d\n", n1);
    printf("Output: %d\n\n", subtractProductAndSum(n1));

    int n2 = 4421;
    printf("Input: n = %d\n", n2);
    printf("Output: %d\n\n", subtractProductAndSum(n2));

    return 0;
}