// Find the Largest Area of Square Inside Two Rectangles

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    (void)bottomLeftColSize;
    (void)topRightColSize;

    int n = bottomLeftSize;
    long long maxSquare = 0;

    for (int i = 0; i < n - 1; i++) {
        long long a = bottomLeft[i][0], b = bottomLeft[i][1];
        long long c = topRight[i][0], d = topRight[i][1];

        for (int j = i + 1; j < n; j++) {
            long long aj = bottomLeft[j][0], bj = bottomLeft[j][1];
            long long cj = topRight[j][0], dj = topRight[j][1];

            long long minC = (c < cj) ? c : cj;
            long long maxA = (a > aj) ? a : aj;
            long long width = minC - maxA;

            long long minD = (d < dj) ? d : dj;
            long long maxB = (b > bj) ? b : bj;
            long long height = minD - maxB;

            if (width > 0 && height > 0) {
                long long square = (width < height) ? width : height;
                if (square > maxSquare) 
                    maxSquare = square;
            }
        }
    }

    return maxSquare * maxSquare;
}