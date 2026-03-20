/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int computeDiff(int* arr, int size) {
    if (size < 2) 
        return 0;

    int minDiff = INT_MAX;
    for (int i = 0; i < size - 1; i++) {
        int d = arr[i+1] - arr[i];
        if (d > 0 && d < minDiff)
            minDiff = d;
    }
    return minDiff == INT_MAX ? 0 : minDiff;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced.
 */
int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k,
                 int* returnSize, int** returnColumnSizes) {

    int rows = gridSize;
    int cols = gridColSize[0];

    int outRows = rows - k + 1;
    int outCols = cols - k + 1;

    int** res = malloc(outRows * sizeof(int*));
    *returnColumnSizes = malloc(outRows * sizeof(int));

    for (int i = 0; i < outRows; i++) {
        res[i] = malloc(outCols * sizeof(int));
        (*returnColumnSizes)[i] = outCols;
    }

    int* window = malloc(k * k * sizeof(int));

    for (int r = 0; r < outRows; r++) {
        for (int c = 0; c < outCols; c++) {

            int idx = 0;
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    window[idx++] = grid[r+i][c+j];

            qsort(window, k*k, sizeof(int), cmp);
            res[r][c] = computeDiff(window, k*k);
        }
    }

    free(window);
    *returnSize = outRows;

    return res;
}
