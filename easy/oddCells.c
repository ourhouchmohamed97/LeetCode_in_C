// Cells with Odd Values in a Matrix

#include <stdio.h>
#include <stdlib.h>

int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int* rowCounts = (int*)calloc(m, sizeof(int));
    int* colCounts = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < indicesSize; i++) {
        int ri = indices[i][0];
        int ci = indices[i][1];
        rowCounts[ri]++;
        colCounts[ci]++;
    }
    
    int oddCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((rowCounts[i] + colCounts[j]) % 2 == 1) {
                oddCount++;
            }
        }
    }
    
    free(rowCounts);
    free(colCounts);
    
    return oddCount;
}

int main() {
    // Example 1
    int m1 = 2;
    int n1 = 3;
    int indices1[][2] = {{0,1}, {1,1}};
    int indicesSize1 = 2;
    int indicesColSize1[] = {2, 2};
    int** indicesArray1 = (int**)malloc(indicesSize1 * sizeof(int*));
    for (int i = 0; i < indicesSize1; i++) {
        indicesArray1[i] = (int*)malloc(2 * sizeof(int));
        indicesArray1[i][0] = indices1[i][0];
        indicesArray1[i][1] = indices1[i][1];
    }
    int result1 = oddCells(m1, n1, indicesArray1, indicesSize1, indicesColSize1);
    printf("Example 1 Output: %d\n", result1);
    
    for (int i = 0; i < indicesSize1; i++) {
        free(indicesArray1[i]);
    }
    free(indicesArray1);
    
    // Example 2
    int m2 = 2;
    int n2 = 2;
    int indices2[][2] = {{1,1}, {0,0}};
    int indicesSize2 = 2;
    int indicesColSize2[] = {2, 2};
    int** indicesArray2 = (int**)malloc(indicesSize2 * sizeof(int*));
    for (int i = 0; i < indicesSize2; i++) {
        indicesArray2[i] = (int*)malloc(2 * sizeof(int));
        indicesArray2[i][0] = indices2[i][0];
        indicesArray2[i][1] = indices2[i][1];
    }
    int result2 = oddCells(m2, n2, indicesArray2, indicesSize2, indicesColSize2);
    printf("Example 2 Output: %d\n", result2);
    
    for (int i = 0; i < indicesSize2; i++) {
        free(indicesArray2[i]);
    }
    free(indicesArray2);
    
    return 0;
}