// Maximum Building Height

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* arr1 = *(int**)a;
    int* arr2 = *(int**)b;
    return arr1[0] - arr2[0];
}

int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {
    (void)restrictionsColSize;
    int* newElem1 = (int*)malloc(2 * sizeof(int));
    newElem1[0] = 1;
    newElem1[1] = 0;
    
    int* newElem2 = (int*)malloc(2 * sizeof(int));
    newElem2[0] = n;
    newElem2[1] = n - 1;
    
    int newSize = restrictionsSize + 2;
    int** res = (int**)malloc(newSize * sizeof(int*));
    for (int i = 0; i < restrictionsSize; i++) {
        res[i] = restrictions[i];
    }
    res[restrictionsSize] = newElem1;
    res[restrictionsSize + 1] = newElem2;
    qsort(res, newSize, sizeof(int*), cmp);
    
    for (int i = newSize - 2; i >= 0; --i) {
        int val = res[i+1][1] + res[i+1][0] - res[i][0];
        if (val < res[i][1]) {
            res[i][1] = val;
        }
    }
    
    int ans = 0; 

    for (int i = 1; i < newSize; ++i) {
        int val = res[i-1][1] + res[i][0] - res[i-1][0];
        if (val < res[i][1]) {
            res[i][1] = val;
        }

        int mid = (int)(((long long)res[i-1][1] + res[i][0] - res[i-1][0] + res[i][1]) / 2);
        if (mid > ans) {
            ans = mid;
        }
    }
    free(newElem1);
    free(newElem2);
    free(res);
    
    return ans; 
}
