// Minimum Time Visiting All Points

#include <stdio.h>
#include <stdlib.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int totalTime = 0;
    for (int i = 0; i < pointsSize - 1; i++) {
        int dx = abs(points[i+1][0] - points[i][0]);
        int dy = abs(points[i+1][1] - points[i][1]);
        totalTime += (dx > dy) ? dx : dy;
    }
    return totalTime;
}

int main() {
    // Example 1: points = [[1,1],[3,4],[-1,0]]
    int points1Data[3][2] = {{1,1}, {3,4}, {-1,0}};
    int points1Size = 3;
    int points1ColSize = 2;
    int** points1 = (int**)malloc(points1Size * sizeof(int*));
    for (int i = 0; i < points1Size; i++) {
        points1[i] = (int*)malloc(points1ColSize * sizeof(int));
        points1[i][0] = points1Data[i][0];
        points1[i][1] = points1Data[i][1];
    }
    int result1 = minTimeToVisitAllPoints(points1, points1Size, &points1ColSize);
    printf("Example 1 Output: %d\n", result1); // Expected: 7

    // Free memory for points1
    for (int i = 0; i < points1Size; i++) {
        free(points1[i]);
    }
    free(points1);

    // Example 2: points = [[3,2],[-2,2]]
    int points2Data[2][2] = {{3,2}, {-2,2}};
    int points2Size = 2;
    int points2ColSize = 2;
    int** points2 = (int**)malloc(points2Size * sizeof(int*));
    for (int i = 0; i < points2Size; i++) {
        points2[i] = (int*)malloc(points2ColSize * sizeof(int));
        points2[i][0] = points2Data[i][0];
        points2[i][1] = points2Data[i][1];
    }
    int result2 = minTimeToVisitAllPoints(points2, points2Size, &points2ColSize);
    printf("Example 2 Output: %d\n", result2); // Expected: 5

    // Free memory for points2
    for (int i = 0; i < points2Size; i++) {
        free(points2[i]);
    }
    free(points2);

    return 0;
}