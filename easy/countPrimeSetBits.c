// Prime Number of Set Bits in Binary Representation

#include <stdio.h>
#include <stdbool.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int countPrimeSetBits(int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        int bits = countSetBits(i);
        if (isPrime(bits)) {
            count++;
        }
    }
    return count;
}

int main() {
    // Example 1
    int left1 = 6, right1 = 10;
    printf("Input: left = %d, right = %d\n", left1, right1);
    printf("Output: %d\n", countPrimeSetBits(left1, right1));

    // Example 2
    int left2 = 10, right2 = 15;
    printf("Input: left = %d, right = %d\n", left2, right2);
    printf("Output: %d\n", countPrimeSetBits(left2, right2));

    return 0;
}