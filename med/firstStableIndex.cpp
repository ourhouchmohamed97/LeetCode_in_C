// Smallest Stable Index II

class Solution {
public:
    int firstStableIndex(const vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) return -1;

        int candidate  = 0;
        int runningMax = INT_MIN;
        int prefixMax  = INT_MIN;

        for (int i = 0; i < n; ++i) {
            runningMax = max(runningMax, nums[i]);

            if (i == candidate)
                prefixMax = max(prefixMax, nums[i]);
            if (nums[i] < prefixMax - k) {
                candidate = i + 1;
                prefixMax = runningMax;
            }
        }

        return candidate < n ? candidate : -1;
    }
};