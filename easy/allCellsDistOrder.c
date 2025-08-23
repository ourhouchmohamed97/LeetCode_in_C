// Matrix Cells in Distance Order

#include <stdio.h>
#include <stdlib.h>

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));
    *returnSize = total;
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[index] = malloc(2 * sizeof(int));
            result[index][0] = i;
            result[index][1] = j;
            (*returnColumnSizes)[index] = 2;
            index++;
        }
    }
    
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            int dist1 = abs(result[j][0] - rCenter) + abs(result[j][1] - cCenter);
            int dist2 = abs(result[j+1][0] - rCenter) + abs(result[j+1][1] - cCenter);
            if (dist1 > dist2) {
                int* temp = result[j];
                result[j] = result[j+1];
                result[j+1] = temp;
            }
        }
    }
    
    return result;
}

int main() {
    int rows = 2, cols = 2, rCenter = 0, cCenter = 1;
    int returnSize;
    int* returnColumnSizes;
    
    int** result = allCellsDistOrder(rows, cols, rCenter, cCenter, &returnSize, &returnColumnSizes);
    
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d]", result[i][0], result[i][1]);
        if (i < returnSize - 1) {
            printf(",");
        }
        free(result[i]);
    }
    printf("]\n");
    
    free(result);
    free(returnColumnSizes);
    
    return 0;
}