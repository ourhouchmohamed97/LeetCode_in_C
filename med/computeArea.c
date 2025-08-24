// Rectangle Area

#include <stdio.h>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    
    int x_overlap = (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1);
    if (x_overlap < 0) x_overlap = 0;
    
    int y_overlap = (ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1);
    if (y_overlap < 0) y_overlap = 0;
    
    int overlap_area = x_overlap * y_overlap;
    
    return area1 + area2 - overlap_area;
}

int main() {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4;
    int bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    printf("%d\n", computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));

    ax1 = -2; ay1 = -2; ax2 = 2; ay2 = 2;
    bx1 = -2; by1 = -2; bx2 = 2; by2 = 2;
    printf("%d\n", computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));

    return 0;
}