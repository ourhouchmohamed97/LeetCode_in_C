// Find the Minimum Area to Cover All Ones I

#include <stdio.h>
#include <limits.h>

int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int minRow = INT_MAX;
    int maxRow = INT_MIN;
    int minCol = INT_MAX;
    int maxCol = INT_MIN;
    int found = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                found = 1;
                if (i < minRow) minRow = i;
                if (i > maxRow) maxRow = i;
                if (j < minCol) minCol = j;
                if (j > maxCol) maxCol = j;
            }
        }
    }
    
    if (!found) {
        return 0;
    }
    
    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;
    return height * width;
}

int main() {
    int grid1[2][3] = {{0,1,0},{1,0,1}};
    int* grid1Ptr[2] = {grid1[0], grid1[1]};
    int gridColSize1[2] = {3, 3};
    int gridSize1 = 2;
    printf("%d\n", minimumArea(grid1Ptr, gridSize1, gridColSize1));
    
    int grid2[2][2] = {{1,0},{0,0}};
    int* grid2Ptr[2] = {grid2[0], grid2[1]};
    int gridColSize2[2] = {2, 2};
    int gridSize2 = 2;
    printf("%d\n", minimumArea(grid2Ptr, gridSize2, gridColSize2));
    
    return 0;
}