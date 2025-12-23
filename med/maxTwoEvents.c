// Two Best Non-Overlapping Events

int cmpEvents(const void *pa, const void *pb) {
    const int *a = *(const int * const *)pa;
    const int *b = *(const int * const *)pb;
    if (a[0] != b[0]) return (a[0] < b[0]) ? -1 : 1;
    if (a[1] != b[1]) return (a[1] < b[1]) ? -1 : 1;
    return 0;
}

int lower_bound_int(const int *arr, int n, int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize) {
    (void)eventsColSize;

    qsort(events, eventsSize, sizeof(events[0]), cmpEvents);

    int n = eventsSize;
    int *starts = (int *)malloc(sizeof(int) * n);
    int *suffix = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        starts[i] = events[i][0];
    }

    suffix[n - 1] = events[n - 1][2];
    for (int i = n - 2; i >= 0; i--) {
        int v = events[i][2];
        suffix[i] = suffix[i + 1] > v ? suffix[i + 1] : v;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound_int(starts, n, events[i][1] + 1);
        int val = events[i][2];
        if (idx < n) val += suffix[idx];
        if (val > res) res = val;
    }

    free(starts);
    free(suffix);
    return res;
}