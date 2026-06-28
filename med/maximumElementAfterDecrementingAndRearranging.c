// Maximum Element After Decreasing and Rearranging

#include <stdlib.h>

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    int res = 0, n = arrSize;
    int* counts = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        counts[(num < n) ? num : n]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (counts[i] != 0) {
            if (i > res) {
                int add = (i - res < counts[i]) ? (i - res) : counts[i];
                res += add;
            } else {
                res += 1;
            }
        }
    }
    
    free(counts);
    return res;
}