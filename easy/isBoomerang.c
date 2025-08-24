// Valid Boomerang

#include <stdio.h>
#include <stdbool.h>

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    int x1 = points[0][0], y1 = points[0][1];
    int x2 = points[1][0], y2 = points[1][1];
    int x3 = points[2][0], y3 = points[2][1];
    
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) {
        return false;
    }
    
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return area != 0;
}

int main() {
    int points1[3][2] = {{1,1}, {2,3}, {3,2}};
    int* p1[3] = {points1[0], points1[1], points1[2]};
    int colSize1 = 2;
    printf("%s\n", isBoomerang(p1, 3, &colSize1) ? "true" : "false");

    int points2[3][2] = {{1,1}, {2,2}, {3,3}};
    int* p2[3] = {points2[0], points2[1], points2[2]};
    int colSize2 = 2;
    printf("%s\n", isBoomerang(p2, 3, &colSize2) ? "true" : "false");

    return 0;
}