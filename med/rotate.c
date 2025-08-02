// Rotate Image

#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < matrixSize; i++) {
        int left = 0;
        int right = matrixSize - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

void printMatrix(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example 1
    int size1 = 3;
    int* matrix1[] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}
    };
    int colSize1[] = {3, 3, 3};
    
    printf("Original Matrix (Example 1):\n");
    printMatrix(matrix1, size1);
    
    rotate(matrix1, size1, colSize1);
    
    printf("\nRotated Matrix (Example 1):\n");
    printMatrix(matrix1, size1);
    
    // Example 2
    int size2 = 4;
    int* matrix2[] = {
        (int[]){5, 1, 9, 11},
        (int[]){2, 4, 8, 10},
        (int[]){13, 3, 6, 7},
        (int[]){15, 14, 12, 16}
    };
    int colSize2[] = {4, 4, 4, 4};
    
    printf("\nOriginal Matrix (Example 2):\n");
    printMatrix(matrix2, size2);
    
    rotate(matrix2, size2, colSize2);
    
    printf("\nRotated Matrix (Example 2):\n");
    printMatrix(matrix2, size2);
    
    return 0;
}