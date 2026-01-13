// Separate Squares I

typedef long long ll;

typedef struct {
    ll y;
    ll delta;
} Entry;

static int cmpEntry(const void* a, const void* b) {
    const Entry* ea = (const Entry*)a;
    const Entry* eb = (const Entry*)b;
    if (ea->y < eb->y) return -1;
    if (ea->y > eb->y) return 1;
    return 0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    (void)squaresColSize;

    ll total = 0;

    Entry* diff = (Entry*)malloc(sizeof(Entry) * (2 * squaresSize));
    int diffSize = 0;

    for (int i = 0; i < squaresSize; i++) {
        ll y = squares[i][1];
        ll s = squares[i][2];
        total += s * s;
        diff[diffSize++] = (Entry){y, s};
        diff[diffSize++] = (Entry){y + s, -s};
    }

    qsort(diff, diffSize, sizeof(Entry), cmpEntry);

    ll* curr = (ll*)malloc(sizeof(ll) * diffSize);
    ll* diff2 = (ll*)malloc(sizeof(ll) * diffSize);
    int currSize = 0;

    for (int i = 0; i < diffSize; ) {
        ll y = diff[i].y;
        ll sum = 0;
        while (i < diffSize && diff[i].y == y) {
            sum += diff[i].delta;
            i++;
        }
        curr[currSize] = y;
        diff2[currSize] = sum;
        currSize++;
    }

    ll area = 0;
    ll target = 0;

    for (int i = 0; i + 1 < currSize; i++) {
        ll y = curr[i];
        ll y2 = curr[i + 1];

        target += diff2[i];
        area += target * (y2 - y);

        if (area * 2LL >= total) {
            double ans = (double)y2 - (double)(area * 2LL - total) / (double)(target * 2LL);
            free(diff);
            free(curr);
            free(diff2);
            return ans;
        }
    }

    double ret = (double)curr[currSize - 1];
    free(diff);
    free(curr);
    free(diff2);
    return ret;
}