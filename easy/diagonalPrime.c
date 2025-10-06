// Prime In Diagonal

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Helper function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
    int n = numsSize;
    int maxPrime = 0;

    for (int i = 0; i < n; i++) {
        int a = nums[i][i];
        int b = nums[i][n - i - 1];

        if (isPrime(a) && a > maxPrime) maxPrime = a;
        if (isPrime(b) && b > maxPrime) maxPrime = b;
    }

    return maxPrime;
}

// Example test
int main() {
    int nums1Data[3][3] = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11}
    };
    int* nums1[3];
    int colSize1 = 3;
    for (int i = 0; i < 3; i++) nums1[i] = nums1Data[i];
    printf("Example 1 Output: %d\n", diagonalPrime(nums1, 3, &colSize1)); // Expected 11

    int nums2Data[3][3] = {
        {1, 2, 3},
        {5, 17, 7},
        {9, 11, 10}
    };
    int* nums2[3];
    int colSize2 = 3;
    for (int i = 0; i < 3; i++) nums2[i] = nums2Data[i];
    printf("Example 2 Output: %d\n", diagonalPrime(nums2, 3, &colSize2)); // Expected 17

    return 0;
}
