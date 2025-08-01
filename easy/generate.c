// Pascal's Triangle

#include <stdlib.h>
#include <stdio.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;
    
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}

int main() {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < returnSize; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);
    
    return 0;
}