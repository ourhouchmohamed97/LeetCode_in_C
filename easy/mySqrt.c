// Sqrt(x)

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0) return 0;
    int left = 1, right = x;
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) { // To avoid overflow, compare mid with x/mid instead of mid*mid with x
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x1 = 4;
    printf("The square root of %d is %d\n", x1, mySqrt(x1)); // Output: 2

    int x2 = 8;
    printf("The square root of %d is %d\n", x2, mySqrt(x2)); // Output: 2

    int x3 = 16;
    printf("The square root of %d is %d\n", x3, mySqrt(x3)); // Output: 4

    int x4 = 1;
    printf("The square root of %d is %d\n", x4, mySqrt(x4)); // Output: 1

    return 0;
}