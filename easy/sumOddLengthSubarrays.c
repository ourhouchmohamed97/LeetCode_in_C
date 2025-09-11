// Sum of All Odd Length Subarrays

#include <stdio.h>

int sumOddLengthSubarrays(int* arr, int arrSize) {
    long long sum = 0;
    for (int i = 0; i < arrSize; ++i) {
        long long left = i + 1;
        long long right = arrSize - i;
        long long total = left * right;
        long long oddCount = (total + 1) / 2;
        sum += oddCount * arr[i];
    }
    return (int)sum;
}

int main(void) {
    int a1[] = {1,4,2,5,3};
    printf("%d\n", sumOddLengthSubarrays(a1, 5)); // 58

    int a2[] = {1,2};
    printf("%d\n", sumOddLengthSubarrays(a2, 2)); // 3

    int a3[] = {10,11,12};
    printf("%d\n", sumOddLengthSubarrays(a3, 3)); // 66

    return 0;
}
