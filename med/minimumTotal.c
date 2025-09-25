// Triangle

#include <stdio.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row = triangleSize - 2; row >= 0; row--) {
        for (int col = 0; col < triangleColSize[row]; col++) {
            int left = triangle[row + 1][col];
            int right = triangle[row + 1][col + 1];
            triangle[row][col] += (left < right ? left : right);
        }
    }
    return triangle[0][0];
}

int main() {
    int row0[] = {2};
    int row1[] = {3, 4};
    int row2[] = {6, 5, 7};
    int row3[] = {4, 1, 8, 3};

    int* triangle[] = {row0, row1, row2, row3};
    int triangleColSize[] = {1, 2, 3, 4};
    int triangleSize = 4;

    int result = minimumTotal(triangle, triangleSize, triangleColSize);
    printf("%d\n", result);

    return 0;
}
