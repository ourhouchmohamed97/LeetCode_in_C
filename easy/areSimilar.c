// Matrix Similarity After Cyclic Shifts

#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int rows = matSize;
    int cols = *matColSize;
    k %= cols;

    if (k == 0) {
        return true; 
    }
    
    for (int i = 0; i < rows; i++) {
        int* shifted_row = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            shifted_row[j] = mat[i][(j + k) % cols];
        }
        
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != shifted_row[j]) {
                free(shifted_row);
                return false; 
            }
        }
        
        free(shifted_row);
    }
    
    return true;
}