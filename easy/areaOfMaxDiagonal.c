// Maximum Area of Longest Diagonal Rectangle

#include <stdio.h>
#include <stdlib.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxDiagSq = 0;
    int maxArea = 0;
    
    for (int i = 0; i < dimensionsSize; i++) {
        int l = dimensions[i][0];
        int w = dimensions[i][1];
        int diagSq = l * l + w * w;
        int area = l * w;
        
        if (diagSq > maxDiagSq) {
            maxDiagSq = diagSq;
            maxArea = area;
        } else if (diagSq == maxDiagSq) {
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    
    return maxArea;
}

int main() {
    // Example 1: dimensions = [[9,3],[8,6]]
    int numRects1 = 2;
    int* dims1[] = {(int[]){9, 3}, (int[]){8, 6}};
    int colSizes1[] = {2, 2};
    int result1 = areaOfMaxDiagonal(dims1, numRects1, colSizes1);
    printf("Example 1 Output: %d\n", result1);  // Expected: 48

    // Example 2: dimensions = [[3,4],[4,3]]
    int numRects2 = 2;
    int* dims2[] = {(int[]){3, 4}, (int[]){4, 3}};
    int colSizes2[] = {2, 2};
    int result2 = areaOfMaxDiagonal(dims2, numRects2, colSizes2);
    printf("Example 2 Output: %d\n", result2);  // Expected: 12

    return 0;
}