// Valid Perfect Square

#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    if (num < 2) return true;

    long left = 2, right = num / 2;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;

        if (square == num) {
            return true;
        } else if (square < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (isPerfectSquare(num)) {
        printf("%d is a perfect square.\n", num);
    } else {
        printf("%d is NOT a perfect square.\n", num);
    }

    return 0;
}
