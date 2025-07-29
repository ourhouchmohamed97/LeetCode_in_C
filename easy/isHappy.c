// Happy Number

#include <stdio.h>
#include <stdbool.h>

// Helper function to calculate the sum of squares of digits
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Floyd’s cycle detection algorithm to determine if n is a happy number
bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isHappy(n)) {
        printf("%d is a happy number.\n", n);
    } else {
        printf("%d is not a happy number.\n", n);
    }

    return 0;
}
