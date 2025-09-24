// Count Integers With Even Digit Sum

#include <stdio.h>

int digitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int countEven(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (digitSum(i) % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    printf("%d\n", countEven(4));   // Output: 2
    printf("%d\n", countEven(30));  // Output: 14
    return 0;
}
