#include <stdio.h>

char* triangleType(int* nums, int numsSize) {
    int a = nums[0], b = nums[1], c = nums[2];
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }

    if (a == b && b == c) {
        return "equilateral";
    } else if (a == b || b == c || a == c) {
        return "isosceles";
    } else {
        return "scalene";
    }
}

int main() {
    int nums[] = {4, 4, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%s\n", triangleType(nums, size)); // Output: scalene
    return 0;
}