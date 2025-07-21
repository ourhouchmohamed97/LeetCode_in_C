// Set Matrix Zeroes

#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return;
    
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int first_row_zero = 0;
    int first_col_zero = 0;
    
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            first_row_zero = 1;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            first_col_zero = 1;
            break;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (first_row_zero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (first_col_zero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1 = 3, cols1 = 3;
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*)malloc(cols1 * sizeof(int));
    }
    matrix1[0][0] = 1; matrix1[0][1] = 1; matrix1[0][2] = 1;
    matrix1[1][0] = 1; matrix1[1][1] = 0; matrix1[1][2] = 1;
    matrix1[2][0] = 1; matrix1[2][1] = 1; matrix1[2][2] = 1;
    
    printf("Example 1 - Input:\n");
    printMatrix(matrix1, rows1, cols1);
    
    setZeroes(matrix1, rows1, &cols1);
    
    printf("\nExample 1 - Output:\n");
    printMatrix(matrix1, rows1, cols1);

    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    
    printf("\n----------------------\n");
    
    // Example 2
    int rows2 = 3, cols2 = 4;
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*)malloc(cols2 * sizeof(int));
    }
    matrix2[0][0] = 0; matrix2[0][1] = 1; matrix2[0][2] = 2; matrix2[0][3] = 0;
    matrix2[1][0] = 3; matrix2[1][1] = 4; matrix2[1][2] = 5; matrix2[1][3] = 2;
    matrix2[2][0] = 1; matrix2[2][1] = 3; matrix2[2][2] = 1; matrix2[2][3] = 5;
    
    printf("Example 2 - Input:\n");
    printMatrix(matrix2, rows2, cols2);
    
    setZeroes(matrix2, rows2, &cols2);
    
    printf("\nExample 2 - Output:\n");
    printMatrix(matrix2, rows2, cols2);
    
    // Free memory for Example 2
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    
    return 0;
}