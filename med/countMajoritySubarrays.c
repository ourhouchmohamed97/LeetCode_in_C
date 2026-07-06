#include <stdio.h>

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int n = numsSize;
    long long ans = 0;

    for (int l = 0; l < n; l++) {
        int targetCount = 0;

        for (int r = l; r < n; r++) {
            if (nums[r] == target) {
                targetCount++;
            }

            int len = r - l + 1;

            if (targetCount > len / 2) {
                ans++;
            }
        }
    }

    return ans;
}
