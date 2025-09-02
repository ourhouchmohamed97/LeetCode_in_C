// Find the Number of Ways to Place People I

#include <stdio.h>
#include <stdlib.h>

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int count = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            if (i == j) continue;
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            if (x1 <= x2 && y1 >= y2) {
                if (x1 == x2 && y1 == y2) continue;
                int valid = 1;
                for (int k = 0; k < pointsSize; k++) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];
                    if (x >= x1 && x <= x2 && y >= y2 && y <= y1) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int pointsData[3][2] = {{3,1}, {1,3}, {1,1}};
    int pointsSize = 3;
    int pointsColSize = 2;

    int** points = (int**)malloc(pointsSize * sizeof(int*));
    for (int i = 0; i < pointsSize; i++) {
        points[i] = (int*)malloc(pointsColSize * sizeof(int));
        points[i][0] = pointsData[i][0];
        points[i][1] = pointsData[i][1];
    }

    int result = numberOfPairs(points, pointsSize, &pointsColSize);
    printf("Output: %d\n", result); // Expected: 2

    for (int i = 0; i < pointsSize; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}