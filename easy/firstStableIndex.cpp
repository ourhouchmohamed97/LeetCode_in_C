// Smallest Stable Index I

class Solution {
public:
    int firstStableIndex(const vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) return -1;
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        int prefixMax = nums[0];
        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, nums[i]);
            if (prefixMax - suffixMin[i] <= k) return i;
        }
        return -1;
    }
};