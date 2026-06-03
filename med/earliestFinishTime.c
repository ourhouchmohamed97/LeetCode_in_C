// Earliest Finish Time for Land and Water Rides II

int calculate(int* start1, int* dur1, int size1, int* start2, int* dur2, int size2) {
    int first_end = INT_MAX;
    for (int i = 0; i < size1; i++) {
        int end = start1[i] + dur1[i];
        if (end < first_end) {
            first_end = end;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < size2; i++) {
        int finish = (first_end > start2[i] ? first_end : start2[i]) + dur2[i];
        if (finish < ans) {
            ans = finish;
        }
    }
    return ans;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int land_first = calculate(
        landStartTime,
        landDuration,
        landStartTimeSize,
        waterStartTime,
        waterDuration,
        waterStartTimeSize
    );
    int water_first = calculate(
        waterStartTime,
        waterDuration,
        waterStartTimeSize,
        landStartTime,
        landDuration,
        landStartTimeSize
    );
    return land_first < water_first ? land_first : water_first;
}
