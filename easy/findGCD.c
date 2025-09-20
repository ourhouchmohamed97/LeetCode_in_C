// Find Greatest Common Divisor of Array

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int findGCD(int* nums, int numsSize) {
    int mn = nums[0], mx = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < mn) mn = nums[i];
        if (nums[i] > mx) mx = nums[i];
    }
    return gcd(mn, mx);
}

int main() {
    int nums[] = {2, 5, 6, 9, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", findGCD(nums, size));
    return 0;
}
