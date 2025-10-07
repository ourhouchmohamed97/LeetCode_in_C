// Sum Multiples

#include <stdio.h>

int sumOfMultiples(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            sum += i;
    }
    return sum;
}

int main() {
    int n;

    // Example test 1
    n = 10;
    printf("Sum of multiples up to %d = %d\n", n, sumOfMultiples(n));

    // Example test 2
    n = 20;
    printf("Sum of multiples up to %d = %d\n", n, sumOfMultiples(n));

    // Example test 3
    n = 50;
    printf("Sum of multiples up to %d = %d\n", n, sumOfMultiples(n));

    // Example test 4 (custom input)
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of multiples up to %d = %d\n", n, sumOfMultiples(n));

    return 0;
}
