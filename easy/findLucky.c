#include <stdio.h>

int findLucky(int* arr, int arrSize) {
    int freq[501] = {0};
    for (int i = 0; i < arrSize; i++)
    {
        freq[arr[i]]++;
    }
    int maxLucky = -1;
    for(int i = 1; i <= 500; i++)
    {
        if(freq[i] == i)
        {
            if(freq[i] > maxLucky)
                maxLucky = freq[i];
        }
    }
    return maxLucky;
}

int main() {
    int arr1[] = {2, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output 1: %d\n", findLucky(arr1, size1)); // Expected: 2

    int arr2[] = {1, 2, 2, 3, 3, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output 2: %d\n", findLucky(arr2, size2)); // Expected: 3

    int arr3[] = {2, 2, 2, 3, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Output 3: %d\n", findLucky(arr3, size3)); // Expected: -1

    return 0;
}