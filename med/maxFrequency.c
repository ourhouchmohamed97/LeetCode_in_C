// Maximum Frequency of an Element After Performing Operations I

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int mx = nums[0];
    for (int i = 1; i < numsSize; i++) if (nums[i] > mx) mx = nums[i];
    int n = mx + k + 2;
    int* f = calloc(n, sizeof(int));
    for (int i = 0; i < numsSize; i++) f[nums[i]]++;

    int* pre = calloc(n, sizeof(int));
    pre[0] = f[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + f[i];

    int ans = 0;
    for (int t = 0; t < n; t++) {
        if (f[t] == 0 && numOperations == 0) continue;
        int l = t - k > 0 ? t - k : 0;
        int r = t + k < n - 1 ? t + k : n - 1;
        int tot = pre[r] - (l > 0 ? pre[l - 1] : 0);
        int adj = tot - f[t];
        int val = f[t] + (numOperations < adj ? numOperations : adj);
        if (val > ans) ans = val;
    }

    free(f);
    free(pre);
    return ans;
}

int main() {
    int nums1[] = {1, 4, 5};
    printf("%d\n", maxFrequency(nums1, 3, 1, 2)); // Expected: 2

    int nums2[] = {5, 11, 20, 20};
    printf("%d\n", maxFrequency(nums2, 4, 5, 1)); // Expected: 2

    int nums3[] = {1, 90};
    printf("%d\n", maxFrequency(nums3, 2, 76, 1)); // Expected: 1 ✅

    return 0;
}