// Maximum Matrix Sum

#include <limits.h>

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long totalSum = 0;
    int neg = 0;
    int minAbs = INT_MAX;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int v = matrix[i][j];
            if (v < 0) neg++;
            int av = abs(v);
            totalSum += av;
            if (av < minAbs) minAbs = av;
        }
    }

    return (neg % 2 == 0) ? totalSum : totalSum - 2LL * minAbs;
}