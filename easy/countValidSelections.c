// Make Array Elements Equal to Zero

#include <stdio.h>
#include <string.h>

static int simulate_once(const int *nums, int n, int start, int dir) {
    int a[1005];
    memcpy(a, nums, n * sizeof(int));
    int curr = start, d = dir;
    while (curr >= 0 && curr < n) {
        if (a[curr] == 0) {
            curr += d;
        } else {
            a[curr] -= 1;
            d = -d;
            curr += d;
        }
    }
    for (int i = 0; i < n; ++i) if (a[i] != 0) return 0;
    return 1;
}

int countValidSelections(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            ans += simulate_once(nums, numsSize, i, +1);
            ans += simulate_once(nums, numsSize, i, -1);
        }
    }
    return ans;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[1005];
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = countValidSelections(a, n);
    printf("%d\n", ans);
    return 0;
}
