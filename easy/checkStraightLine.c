// Check If It Is a Straight Line

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    if (coordinatesSize == 2) {
        return true;
    }
    
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    
    int dx = x1 - x0;
    int dy = y1 - y0;
    
    for (int i = 2; i < coordinatesSize; i++) {
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];
        int dxi = xi - x0;
        int dyi = yi - y0;
        
        if (dx * dyi != dy * dxi) {
            return false;
        }
    }
    
    return true;
}

int main() {
    // Example 1
    int coordinates1[][2] = {{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}};
    int coordinatesSize1 = 6;
    int coordinatesColSize1[] = {2, 2, 2, 2, 2, 2};
    int** coordinatesArray1 = (int**)malloc(coordinatesSize1 * sizeof(int*));
    for (int i = 0; i < coordinatesSize1; i++) {
        coordinatesArray1[i] = (int*)malloc(2 * sizeof(int));
        coordinatesArray1[i][0] = coordinates1[i][0];
        coordinatesArray1[i][1] = coordinates1[i][1];
    }
    bool result1 = checkStraightLine(coordinatesArray1, coordinatesSize1, coordinatesColSize1);
    printf("Example 1 Output: %s\n", result1 ? "true" : "false");
    
    for (int i = 0; i < coordinatesSize1; i++) {
        free(coordinatesArray1[i]);
    }
    free(coordinatesArray1);
    
    // Example 2
    int coordinates2[][2] = {{1,1}, {2,2}, {3,4}, {4,5}, {5,6}, {7,7}};
    int coordinatesSize2 = 6;
    int coordinatesColSize2[] = {2, 2, 2, 2, 2, 2};
    int** coordinatesArray2 = (int**)malloc(coordinatesSize2 * sizeof(int*));
    for (int i = 0; i < coordinatesSize2; i++) {
        coordinatesArray2[i] = (int*)malloc(2 * sizeof(int));
        coordinatesArray2[i][0] = coordinates2[i][0];
        coordinatesArray2[i][1] = coordinates2[i][1];
    }
    bool result2 = checkStraightLine(coordinatesArray2, coordinatesSize2, coordinatesColSize2);
    printf("Example 2 Output: %s\n", result2 ? "true" : "false");
    
    for (int i = 0; i < coordinatesSize2; i++) {
        free(coordinatesArray2[i]);
    }
    free(coordinatesArray2);
    
    return 0;
}