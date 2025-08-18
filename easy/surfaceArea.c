// Surface Area of 3D Shapes

#include <stdio.h>
#include <stdlib.h>

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int area = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                area += 4 * grid[i][j] + 2;
            }
            if (i > 0) {
                area -= 2 * (grid[i][j] < grid[i-1][j] ? grid[i][j] : grid[i-1][j]);
            }
            if (j > 0) {
                area -= 2 * (grid[i][j] < grid[i][j-1] ? grid[i][j] : grid[i][j-1]);
            }
        }
    }
    return area;
}

int main() {
    // Example 1
    int grid1Size = 2;
    int grid1ColSize[] = {2, 2};
    int* grid1[] = {
        (int[]){1, 2},
        (int[]){3, 4}
    };
    printf("Example 1 Output: %d\n", surfaceArea(grid1, grid1Size, grid1ColSize));

    // Example 2
    int grid2Size = 3;
    int grid2ColSize[] = {3, 3, 3};
    int* grid2[] = {
        (int[]){1, 1, 1},
        (int[]){1, 0, 1},
        (int[]){1, 1, 1}
    };
    printf("Example 2 Output: %d\n", surfaceArea(grid2, grid2Size, grid2ColSize));

    // Example 3
    int grid3Size = 3;
    int grid3ColSize[] = {3, 3, 3};
    int* grid3[] = {
        (int[]){2, 2, 2},
        (int[]){2, 1, 2},
        (int[]){2, 2, 2}
    };
    printf("Example 3 Output: %d\n", surfaceArea(grid3, grid3Size, grid3ColSize));

    return 0;
}