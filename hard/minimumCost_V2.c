// Divide an Array Into Subarrays With Minimum Cost II

#include <limits.h>

long long bitSum[100005];
int bitCount[100005];
int sortedUnique[100005];

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

long long minimumCost(int* nums, int numsSize, int k, int dist) {
    int* temp = malloc(numsSize * sizeof(int));
    memcpy(temp, nums, numsSize * sizeof(int));
    qsort(temp, numsSize, sizeof(int), cmp);
    int m = 0;
    for (int i = 0; i < numsSize; i++)
        if (i == 0 || temp[i] != temp[i - 1]) sortedUnique[m++] = temp[i];
    free(temp);

    memset(bitSum, 0, (m + 1) * sizeof(long long));
    memset(bitCount, 0, (m + 1) * sizeof(int));

    void update(int r, int v, int c) {
        for (; r <= m; r += r & -r) { bitSum[r] += v; bitCount[r] += c; }
    }

    int getRank(int v) {
        int l = 0, h = m - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (sortedUnique[mid] == v) return mid + 1;
            if (sortedUnique[mid] < v) l = mid + 1; else h = mid - 1;
        }
        return -1;
    }

    int maxP = 1; while ((maxP << 1) <= m) maxP <<= 1;
    long long minExtra = LLONG_MAX;
    for (int i = 1; i < numsSize; i++) {
        update(getRank(nums[i]), nums[i], 1);
        if (i > dist + 1) update(getRank(nums[i - dist - 1]), -nums[i - dist - 1], -1);
        if (i >= k - 1) {
            int idx = 0, cc = 0; long long cs = 0;
            for (int p = maxP; p > 0; p >>= 1) {
                if (idx + p <= m && cc + bitCount[idx + p] < k - 1) {
                    idx += p; cc += bitCount[idx]; cs += bitSum[idx];
                }
            }
            if (cc < k - 1) cs += (long long)(k - 1 - cc) * sortedUnique[idx];
            if (cs < minExtra) minExtra = cs;
        }
    }
    return nums[0] + minExtra;
}