// Number of Islands

#include <stdio.h>
#include <stdlib.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return count;
}

int main() {
    char* grid1[] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    int gridSize1 = 4;
    int gridColSize1[] = {5, 5, 5, 5};
    printf("Example 1: %d\n", numIslands(grid1, gridSize1, gridColSize1)); // Expected: 1

    char* grid2[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };
    int gridSize2 = 4;
    int gridColSize2[] = {5, 5, 5, 5};
    printf("Example 2: %d\n", numIslands(grid2, gridSize2, gridColSize2)); // Expected: 3

    return 0;
}