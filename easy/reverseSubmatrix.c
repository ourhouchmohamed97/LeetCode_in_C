/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int** res = malloc(rows * sizeof(int*));
    *returnColumnSizes = malloc(rows * sizeof(int));
    *returnSize = rows;

    for (int i = 0; i < rows; i++) {
        res[i] = malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;

        for (int j = 0; j < cols; j++) {
            res[i][j] = grid[i][j];  
        }
    }

    int l = x;
    int r = x + k - 1;

    while (l <= r) {
        for (int i = y; i < y + k; i++) {
            int temp = res[l][i];
            res[l][i] = res[r][i];
            res[r][i] = temp;
        }
        l++;
        r--;
    }

    return res;
}
