// Maximize Area of Square Hole in Grid

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findLongestConsecutive(int* arr, int size) {
    if (size == 0) return 0;
    
    qsort(arr, size, sizeof(int), compare);
    
    int maxLength = 1;
    int currentLength = 1;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i-1]) {
            continue;
        } else if (arr[i] == arr[i-1] + 1) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    
    return maxLength;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    int maxConsecH = findLongestConsecutive(hBars, hBarsSize);
    int maxConsecV = findLongestConsecutive(vBars, vBarsSize);
    int side = (maxConsecH + 1 < maxConsecV + 1) ? (maxConsecH + 1) : (maxConsecV + 1);
    return side * side;
}
