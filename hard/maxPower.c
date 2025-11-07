// Maximize the Minimum Powered City

#include <stdbool.h>

static bool canAchieve(long long x, int* stations, long long* power, int n, int r, long long k) {
    long long* diff = (long long*)calloc(n + 1, sizeof(long long));
    long long added = 0;
    for (int i = 0; i < n; i++) {
        added += diff[i];
        long long curr = power[i] + added;
        if (curr < x) {
            long long need = x - curr;
            if (need > k) { free(diff); return false; }
            k -= need;
            added += need;
            int end = i + 2 * r + 1;
            if (end < n) diff[end] -= need;
        }
    }
    free(diff);
    return true;
}
long long maxPower(int* stations, int n, int r, int k) {
    long long* prefix = (long long*)calloc(n + 1, sizeof(long long));
    long long* power = (long long*)malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stations[i];
    for (int i = 0; i < n; i++) {
        int left = (i - r < 0) ? 0 : i - r;
        int right = (i + r >= n) ? n - 1 : i + r;
        power[i] = prefix[right + 1] - prefix[left];
    }
    long long lo = 0, hi = prefix[n] + k, ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canAchieve(mid, stations, power, n, r, k)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    free(prefix);
    free(power);
    return ans;
}