// Rectangle Overlap

#include <stdbool.h>
#include <stdio.h>

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    if (rec1[2] <= rec2[0]) {
        return false;
    }
    if (rec1[0] >= rec2[2]) {
        return false;
    }
    if (rec1[3] <= rec2[1]) {
        return false;
    }
    if (rec1[1] >= rec2[3]) {
        return false;
    }
    return true;
}

int main() {
    int rec1[] = {0, 0, 2, 2};
    int rec2[] = {1, 1, 3, 3};
    printf("%d\n", isRectangleOverlap(rec1, 4, rec2, 4));

    int rec3[] = {0, 0, 1, 1};
    int rec4[] = {1, 0, 2, 1};
    printf("%d\n", isRectangleOverlap(rec3, 4, rec4, 4));

    return 0;
}