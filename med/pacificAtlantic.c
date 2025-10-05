// Pacific Atlantic Water Flow

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** heights, int heightsSize, int heightsColSize, int r, int c, bool** visited, int prevHeight) {
    if (r < 0 || r >= heightsSize || c < 0 || c >= heightsColSize || visited[r][c] || heights[r][c] < prevHeight)
        return;
    visited[r][c] = true;
    dfs(heights, heightsSize, heightsColSize, r + 1, c, visited, heights[r][c]);
    dfs(heights, heightsSize, heightsColSize, r - 1, c, visited, heights[r][c]);
    dfs(heights, heightsSize, heightsColSize, r, c + 1, visited, heights[r][c]);
    dfs(heights, heightsSize, heightsColSize, r, c - 1, visited, heights[r][c]);
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    if (heightsSize == 0 || heightsColSize == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int m = heightsSize;
    int n = *heightsColSize;
    bool** pacific = malloc(m * sizeof(bool*));
    bool** atlantic = malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        pacific[i] = calloc(n, sizeof(bool));
        atlantic[i] = calloc(n, sizeof(bool));
    }
    for (int i = 0; i < m; i++)
        dfs(heights, m, n, i, 0, pacific, heights[i][0]);
    for (int j = 0; j < n; j++)
        dfs(heights, m, n, 0, j, pacific, heights[0][j]);
    for (int i = 0; i < m; i++)
        dfs(heights, m, n, i, n - 1, atlantic, heights[i][n - 1]);
    for (int j = 0; j < n; j++)
        dfs(heights, m, n, m - 1, j, atlantic, heights[m - 1][j]);
    int capacity = m * n;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result[*returnSize] = malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);
    return result;
}

int main() {
    int data[5][5] = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    int m = 5, n = 5;
    int* heightsColSize = &n;
    int** heights = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        heights[i] = data[i];
    int returnSize;
    int* returnColumnSizes;
    int** result = pacificAtlantic(heights, m, heightsColSize, &returnSize, &returnColumnSizes);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d]", result[i][0], result[i][1]);
        if (i < returnSize - 1) printf(",");
        free(result[i]);
    }
    printf("]\n");
    free(result);
    free(returnColumnSizes);
    free(heights);
    return 0;
}
