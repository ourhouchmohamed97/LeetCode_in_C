// Largest Submatrix With Rearrangements

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) 
        return 0;

    int m = matrixSize;
    int n = matrixColSize[0];

    int* heights = calloc(n, sizeof(int));
    int* sortedH = malloc(n * sizeof(int));
    int maxArea = 0;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++)
            heights[j] = matrix[i][j] ? heights[j] + 1 : 0;

        for (int j = 0; j < n; j++)
            sortedH[j] = heights[j];

        qsort(sortedH, n, sizeof(int), cmpDesc);

        for (int j = 0; j < n; j++) {
            int area = sortedH[j] * (j + 1);
            if (area > maxArea) maxArea = area;
        }
    }

    free(heights);
    free(sortedH);
    return maxArea;
}