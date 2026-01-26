// Minimum Absolute Difference

#include "limits.h"

static int cmpInt(const void* a, const void* b){
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmpInt);
    int min_diff = INT_MAX;
    for (int i = 0; i < arrSize - 1; i++){
        int diff = arr[i + 1] - arr[i];
        if (diff < min_diff){
            min_diff = diff;
        }
    }
    int count = 0;
    for (int i = 0; i < arrSize - 1; i++){
        if (arr[i + 1] - arr[i] == min_diff)
            count++;
    }
    int** res = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    int idx = 0;
    for (int i = 0; i < arrSize - 1; i++){
        if (arr[i + 1] - arr[i] == min_diff){
            res[idx] = (int*)malloc(sizeof(int) * 2);
            res[idx][0] = arr[i];
            res[idx][1] = arr[i + 1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }
    *returnSize = count;
    return res;
}