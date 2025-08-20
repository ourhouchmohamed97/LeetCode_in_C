// Count Square Submatrices with All Ones

#include <stdio.h>
#include <stdlib.h>

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }
    
    int total = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                int min = dp[i-1][j];
                if (dp[i][j-1] < min) min = dp[i][j-1];
                if (dp[i-1][j-1] < min) min = dp[i-1][j-1];
                dp[i][j] = min + 1;
            } else {
                dp[i][j] = 0;
            }
            total += dp[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return total;
}

int main() {
    // Example 1
    int matrix1[3][4] = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    int rows1 = 3;
    int cols1 = 4;
    int* matrix1Ptr[3];
    for (int i = 0; i < rows1; i++) {
        matrix1Ptr[i] = matrix1[i];
    }
    int result1 = countSquares(matrix1Ptr, rows1, &cols1);
    printf("Output for Example 1: %d\n", result1); // Expected 15

    // Example 2
    int matrix2[3][3] = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    int rows2 = 3;
    int cols2 = 3;
    int* matrix2Ptr[3];
    for (int i = 0; i < rows2; i++) {
        matrix2Ptr[i] = matrix2[i];
    }
    int result2 = countSquares(matrix2Ptr, rows2, &cols2);
    printf("Output for Example 2: %d\n", result2); // Expected 7

    return 0;
}