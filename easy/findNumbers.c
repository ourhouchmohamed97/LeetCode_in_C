// Find Numbers with Even Number of Digits

#include <stdio.h>
#include <stdlib.h>

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num < 0) num = -num;
        int digitCount = 0;
        do {
            digitCount++;
            num /= 10;
        } while (num > 0);
        if (digitCount % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int nums1[] = {12, 345, 2, 6, 7896};
    int nums2[] = {555, 901, 482, 1771};
    printf("Test Case 1: ");
    printf("%d\n", findNumbers(nums1, 5));
    printf("Test Case 2: ");
    printf("%d\n", findNumbers(nums2, 4));
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Output: %d\n", findNumbers(nums, n));
    return 0;
}