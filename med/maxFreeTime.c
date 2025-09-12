// Reschedule Meetings for Maximum Free Time I

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void getGaps(int eventTime, int* startTime, int* endTime, int n, int* gaps) {
    gaps[0] = startTime[0];
    for (int i = 1; i < n; ++i) {
        gaps[i] = startTime[i] - endTime[i - 1];
    }
    gaps[n] = eventTime - endTime[n - 1];
}

int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int n = startTimeSize;
    int* gaps = (int*)malloc((n + 1) * sizeof(int));
    getGaps(eventTime, startTime, endTime, n, gaps);

    int windowSum = 0;
    for (int i = 0; i <= k; ++i) {
        windowSum += gaps[i];
    }

    int ans = windowSum;

    for (int i = k + 1; i <= n; ++i) {
        windowSum += gaps[i] - gaps[i - k - 1];
        ans = max(ans, windowSum);
    }

    free(gaps);
    return ans;
}

int main(){
    int eventTime = 10;
    int k = 2;
    int startTime[] = {1, 3, 5, 7};
    int endTime[] = {2, 4, 6, 8};
    int startTimeSize = sizeof(startTime) / sizeof(startTime[0]);
    int endTimeSize = sizeof(endTime) / sizeof(endTime[0]);

    int result = maxFreeTime(eventTime, k, startTime, startTimeSize, endTime, endTimeSize);
    printf("Maximum free time: %d\n", result);

    return 0;
}