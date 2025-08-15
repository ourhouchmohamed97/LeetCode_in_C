// Largest Triangle Area

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double max_area = 0.0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];
                double area = 0.5 * fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
    }
    return max_area;
}

int main() {
    // Example 1
    int points1[5][2] = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    int* points1_ptr[5];
    for (int i = 0; i < 5; i++) {
        points1_ptr[i] = points1[i];
    }
    int pointsColSize1 = 2;
    double result1 = largestTriangleArea(points1_ptr, 5, &pointsColSize1);
    printf("Example 1 Output: %.5f\n", result1);

    // Example 2
    int points2[3][2] = {{1,0}, {0,0}, {0,1}};
    int* points2_ptr[3];
    for (int i = 0; i < 3; i++) {
        points2_ptr[i] = points2[i];
    }
    int pointsColSize2 = 2;
    double result2 = largestTriangleArea(points2_ptr, 3, &pointsColSize2);
    printf("Example 2 Output: %.5f\n", result2);

    return 0;
}