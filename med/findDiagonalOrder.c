// Diagonal Traverse

#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    if (matSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int m = matSize;
    int n = matColSize[0];
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int row = 0, col = 0;
    int direction = 1;
    
    for (int i = 0; i < *returnSize; i++) {
        result[i] = mat[row][col];
        if (direction == 1) {
            if (col == n - 1) {
                row++;
                direction = -1;
            } else if (row == 0) {
                col++;
                direction = -1;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == m - 1) {
                col++;
                direction = 1;
            } else if (col == 0) {
                row++;
                direction = 1;
            } else {
                row++;
                col--;
            }
        }
    }
    return result;
}

int main() {
    int matSize = 3;
    int matColSize[] = {3, 3, 3};
    int** mat = (int**)malloc(matSize * sizeof(int*));
    for (int i = 0; i < matSize; i++) {
        mat[i] = (int*)malloc(matColSize[i] * sizeof(int));
    }
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    int returnSize;
    int* result = findDiagonalOrder(mat, matSize, matColSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    for (int i = 0; i < matSize; i++) {
        free(mat[i]);
    }
    free(mat);
    free(result);

    return 0;
}