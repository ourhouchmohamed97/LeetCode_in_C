// Special Positions in a Binary Matrix

int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];

    int special = 0;

    for (int r = 0; r < m; r++) {
        int rowSum = 0;
        int col = -1;

        for (int c = 0; c < n; c++) {
            rowSum += mat[r][c];
            if (mat[r][c] == 1) 
                col = c;
        }

        if (rowSum == 1) {
            int colSum = 0;
            for (int rr = 0; rr < m; rr++) 
                colSum += mat[rr][col];
            if (colSum == 1) 
                special++;
        }
    }

    return special;
}