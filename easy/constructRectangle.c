// Construct the Rectangle

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* constructRectangle(int area, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    int W = (int)sqrt(area);
    while (area % W != 0) W--;
    result[0] = area / W;
    result[1] = W;
    return result;
}

int main() {
    int area;
    scanf("%d", &area);
    int returnSize;
    int* result = constructRectangle(area, &returnSize);
    printf("[%d,%d]\n", result[0], result[1]);
    free(result);
    return 0;
}