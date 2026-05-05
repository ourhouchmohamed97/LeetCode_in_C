// Rotate Image

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int i = 0; i < n >> 1; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[~j + n][i];
            matrix[~j + n][i] = matrix[~i + n][~j + n];
            matrix[~i + n][~j + n] = matrix[j][~i + n];
            matrix[j][~i + n] = t;
        }
    }
}
