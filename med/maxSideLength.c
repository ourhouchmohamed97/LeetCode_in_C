// Maximum Side Length of a Square with Sum Less than or Equal to Threshold

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];

    int** pref = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++)
        pref[i] = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] =
                mat[i-1][j-1]
              + pref[i-1][j]
              + pref[i][j-1]
              - pref[i-1][j-1];
        }
    }

    int maxSide = m < n ? m : n;

    while (maxSide > 0) {
        for (int i = 0; i + maxSide <= m; i++) {
            for (int j = 0; j + maxSide <= n; j++) {
                int sum =
                    pref[i+maxSide][j+maxSide]
                  - pref[i][j+maxSide]
                  - pref[i+maxSide][j]
                  + pref[i][j];
                if (sum <= threshold) return maxSide;
            }
        }
        maxSide--;
    }
    return 0;
}