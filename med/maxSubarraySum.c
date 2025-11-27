// Maximum Subarray Sum With Length Divisible by K

#include <limits.h>

long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long s = 0;
    long long ans = LLONG_MIN;

    long long minPrefix[200005];
    int i;

    for (i = 0; i < k; i++) {
        minPrefix[i] = (long long)LLONG_MAX / 4;
    }

    long long prefix = 0;
    minPrefix[(k - 1) % k] = 0;

    for (i = 0; i < numsSize; i++) {
        prefix += nums[i];
        int r = i % k;

        if (minPrefix[r] != (long long)LLONG_MAX / 4) {
            long long cand = prefix - minPrefix[r];
            if (cand > ans) ans = cand;
        }

        if (prefix < minPrefix[r]) {
            minPrefix[r] = prefix;
        }
    }

    return ans;
}