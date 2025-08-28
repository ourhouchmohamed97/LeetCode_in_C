// Sort Matrix by Diagonals

#include <stdio.h>
#include <stdlib.h>

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    for (int startRow = 0; startRow < n; startRow++) {
        int i = startRow, j = 0;
        int len = (n - startRow) < n ? (n - startRow) : n;
        int* arr = (int*)malloc(len * sizeof(int));
        int idx = 0;
        while (i < n && j < n) {
            arr[idx++] = grid[i][j];
            i++;
            j++;
        }
        for (int k = 0; k < idx - 1; k++) {
            for (int l = k + 1; l < idx; l++) {
                if (arr[k] < arr[l]) {
                    int temp = arr[k];
                    arr[k] = arr[l];
                    arr[l] = temp;
                }
            }
        }
        i = startRow, j = 0;
        idx = 0;
        while (i < n && j < n) {
            grid[i][j] = arr[idx++];
            i++;
            j++;
        }
        free(arr);
    }
    
    for (int startCol = 1; startCol < n; startCol++) {
        int i = 0, j = startCol;
        int len = (n - startCol) < n ? (n - startCol) : n;
        int* arr = (int*)malloc(len * sizeof(int));
        int idx = 0;
        while (i < n && j < n) {
            arr[idx++] = grid[i][j];
            i++;
            j++;
        }
        for (int k = 0; k < idx - 1; k++) {
            for (int l = k + 1; l < idx; l++) {
                if (arr[k] > arr[l]) {
                    int temp = arr[k];
                    arr[k] = arr[l];
                    arr[l] = temp;
                }
            }
        }
        i = 0, j = startCol;
        idx = 0;
        while (i < n && j < n) {
            grid[i][j] = arr[idx++];
            i++;
            j++;
        }
        free(arr);
    }
    
    return grid;
}

int main() {
    int n = 3;
    int** grid = (int**)malloc(n * sizeof(int*));
    int gridColSize[] = {3, 3, 3};
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
    }
    grid[0][0] = 1; grid[0][1] = 7; grid[0][2] = 3;
    grid[1][0] = 9; grid[1][1] = 8; grid[1][2] = 2;
    grid[2][0] = 4; grid[2][1] = 5; grid[2][2] = 6;
    
    int returnSize;
    int* returnColumnSizes;
    int** result = sortMatrix(grid, n, gridColSize, &returnSize, &returnColumnSizes);
    
    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
    free(returnColumnSizes);
    
    return 0;
}