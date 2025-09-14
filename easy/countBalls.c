#include <stdio.h>

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    int boxCount[100] = {0};  // digit sum won’t exceed 45 for 10^5, but 100 is safe
    int maxBalls = 0;

    for (int i = lowLimit; i <= highLimit; i++) {
        int box = digitSum(i);
        boxCount[box]++;
        if (boxCount[box] > maxBalls) {
            maxBalls = boxCount[box];
        }
    }

    return maxBalls;
}

int main() {
    printf("%d\n", countBalls(1, 10));   // Output: 2
    printf("%d\n", countBalls(5, 15));   // Output: 2
    printf("%d\n", countBalls(19, 28));  // Output: 2
    return 0;
}
