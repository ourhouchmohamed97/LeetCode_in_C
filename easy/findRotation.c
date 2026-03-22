bool isEqual(int** mat, int** target, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != target[i][j])
                return false;
    return true;
}
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < matSize / 2; i++) {
            for (int j = 0; j < (matSize + 1) / 2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[matSize - 1 - j][i];
                mat[matSize - 1 - j][i] = mat[matSize - 1 - i][matSize - 1 - j];
                mat[matSize - 1 - i][matSize - 1 - j] = mat[j][matSize - 1 - i];
                mat[j][matSize - 1 - i] = temp;
            }
        }

        if (isEqual(mat, target, matSize))
            return true;
    }

    return false;
}
