// Projection Area of 3D Shapes


#include <stdio.h>
#include <stdlib.h>

int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int xy = 0, yz = 0, zx = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                xy++;
            }
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        int max_row = 0;
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > max_row) {
                max_row = grid[i][j];
            }
        }
        yz += max_row;
    }
    
    for (int j = 0; j < gridColSize[0]; j++) {
        int max_col = 0;
        for (int i = 0; i < gridSize; i++) {
            if (j < gridColSize[i] && grid[i][j] > max_col) {
                max_col = grid[i][j];
            }
        }
        zx += max_col;
    }
    
    return xy + yz + zx;
}

int main() {
    int grid1[2][2] = {{1, 2}, {3, 4}};
    int* grid1_ptr[2] = {grid1[0], grid1[1]};
    int gridSize1 = 2;
    int gridColSize1[2] = {2, 2};
    printf("%d\n", projectionArea(grid1_ptr, gridSize1, gridColSize1));
    
    int grid2[1][1] = {{2}};
    int* grid2_ptr[1] = {grid2[0]};
    int gridSize2 = 1;
    int gridColSize2[1] = {1};
    printf("%d\n", projectionArea(grid2_ptr, gridSize2, gridColSize2));
    
    int grid3[2][2] = {{1, 0}, {0, 2}};
    int* grid3_ptr[2] = {grid3[0], grid3[1]};
    int gridSize3 = 2;
    int gridColSize3[2] = {2, 2};
    printf("%d\n", projectionArea(grid3_ptr, gridSize3, gridColSize3));
    
    return 0;
}