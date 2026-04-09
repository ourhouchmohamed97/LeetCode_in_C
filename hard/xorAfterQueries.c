// XOR After Range Multiplication Queries II

#define MOD 1000000007

void quickSort(void **a, int lo, int hi);

int root2(long long val) {
    long long lo = 1, hi = val;
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if (mid * mid > val) hi = mid - 1;
        else lo = mid + 1;
    }
    return hi;
}

long long powMOD(long long x, long long y) {
    long long ans = 1;
    while (y > 0) {
        if (y & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int n = numsSize, t = root2(n);
    quickSort((void**) queries, 0, queriesSize-1);
    int curK = queries[0][2], i = 0;
    long long diff[n+t];
    for (int j = 0; j < n+t; ++j) diff[j] = 1;
    while (i < queriesSize && curK < t) {
        int k = queries[i][2];
        if (curK == k) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][3];
            diff[l] = (diff[l] * v) % MOD;
            r = ((r - l) / k + 1) * k + l;
            diff[r] = (diff[r] * powMOD(v, MOD-2)) % MOD;
            ++i;
        } else {
            for (int j = curK; j < n; ++j) {
                diff[j] = (diff[j] * diff[j-curK]) % MOD;
            }
            for (int j = 0; j < n; ++j) {
                nums[j] = ((long long) nums[j] * diff[j]) % MOD;
            }
            curK = k;
            for (int j = 0; j < n; ++j) diff[j] = 1;
        }
    }
    if (curK < t) {
        for (int j = curK; j < n; ++j) {
            diff[j] = (diff[j] * diff[j-curK]) % MOD;
        }
        for (int j = 0; j < n; ++j) {
            nums[j] = ((long long) nums[j] * diff[j]) % MOD;
        }
    }
    while (i < queriesSize) {
        int l = queries[i][0], r = queries[i][1];
        int k = queries[i][2], v = queries[i++][3];
        for (int j = l; j <= r; j += k) {
            nums[j] = ((long long) nums[j] * v) % MOD;
        }
    }
    int totalXor = 0;
    for (int i = 0; i < n; ++i)  {
        totalXor ^= nums[i];
    }
    return totalXor;
}

int compare (void *x, void *y) {
/*  for ascending, return *x - *y
	for descending return *y - *x */
    return ((int*) x)[2] - ((int*) y)[2];
}

void insertionSort(void **a, int lo, int hi) {
    int i, j;
    void *t;
    for (i = lo+1; i <= hi; ++i) {
        t = a[i];
        j = i-1;
        while (j >= lo && compare(a[j], t) > 0) {
           a[j+1] = a[j];
           --j;
        }
        a[++j] = t;
    }
}

void quickSort(void **a, int lo, int hi) {
    int pi, i, j;
    void *pv, *t;
    if (lo >= hi - 10) {
        insertionSort(a, lo, hi);
        return;
    }
    pi = (lo + hi) / 2;
    pv = a[pi];
    a[pi] = a[hi];
    a[hi] = pv;
    i = lo - 1;
    j = hi;
    do {
        do { i++; } while (compare(a[i], pv) < 0);
        do { j--; } while (compare(a[j], pv) > 0 && j > lo);
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    } while (i < j);
    a[hi] = a[i];
    a[i] = pv;
    quickSort(a, lo, i-1); 
    quickSort(a, i+1, hi);
}