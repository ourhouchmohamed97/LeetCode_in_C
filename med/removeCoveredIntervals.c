// Remove Covered Intervals

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    const int* intervalA = *(const int**)a;
    const int* intervalB = *(const int**)b;

    if (intervalA[0] == intervalB[0]) {
        if (intervalA[1] > intervalB[1]) return -1;
        if (intervalA[1] < intervalB[1]) return 1;
        return 0;
    } else {
        if (intervalA[0] < intervalB[0]) return -1;
        if (intervalA[0] > intervalB[0]) return 1;
        return 0;
    }
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int count = 0;
    int startPoint = intervals[0][0];
    int endPoint = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (startPoint <= intervals[i][0] && intervals[i][1] <= endPoint) {
            count++;
        } else {
            startPoint = intervals[i][0];
            endPoint = intervals[i][1];
        }
    }

    return intervalsSize - count;
}
