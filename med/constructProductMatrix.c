/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MOD 12345
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int rows = gridSize;
    int cols = gridColSize[0]; 

    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(cols * sizeof(int));
    }

    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols; 
    }

    long long total = 1;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            dp[i][j] = total;
            total = (total * grid[i][j]) % MOD;
        }
    }

    total = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dp[i][j] = (dp[i][j] * total) % MOD;
            total = (total * grid[i][j]) % MOD;
        }
    }

    *returnSize = rows; 

    return dp;
}
