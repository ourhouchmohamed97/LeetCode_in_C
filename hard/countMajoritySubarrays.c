// Count Subarrays With Majority Element II

#include <stdlib.h>

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int n = numsSize;
    int* freq = (int*)calloc(2 * n + 1, sizeof(int));
    freq[n] = 1;
    int idx = n;
    long long res = 0;
    long long pref = 0;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == target) {
            pref += freq[idx];
            idx++;
        } else {
            idx--;
            pref -= freq[idx];
        }
        freq[idx]++;
        res += pref;
    }

    free(freq);
    return res;
}