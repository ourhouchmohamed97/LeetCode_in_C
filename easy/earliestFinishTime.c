// Earliest Finish Time for Land and Water Rides I

#include <limits.h>


static inline int max_val(int a, int b) { 
    return a > b ? a : b; 
}
static inline int min_val(int a, int b) {
    return a < b ? a : b; 
}
int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int res = INT_MAX;
    int n = landStartTimeSize;
    int m = waterStartTimeSize;

    for (int i = 0; i < n; i++) {
        int landFinish = landStartTime[i] + landDuration[i];
        for (int j = 0; j < m; j++) {
            int waterStart = max_val(landFinish, waterStartTime[j]);
            int totalFinish = waterStart + waterDuration[j];
            res = min_val(res, totalFinish);
        }
    }

    for (int j = 0; j < m; j++) {
        int waterFinish = waterStartTime[j] + waterDuration[j];
        for (int i = 0; i < n; i++) {
            int landStart = max_val(waterFinish, landStartTime[i]);
            int totalFinish = landStart + landDuration[i];
            res = min_val(res, totalFinish);
        }
    }

    return res;
}