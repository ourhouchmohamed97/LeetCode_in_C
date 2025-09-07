// Number of Steps to Reduce a Number to Zero

#include <stdio.h>

int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num -= 1;
        steps++;
    }
    return steps;
}

int main() {
    int num1 = 14;
    printf("%d\n", numberOfSteps(num1));

    int num2 = 8;
    printf("%d\n", numberOfSteps(num2));

    int num3 = 123;
    printf("%d\n", numberOfSteps(num3));

    return 0;
}