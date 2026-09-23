// Minimum Operations to Reduce X to Zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const long long target = accumulate(nums.begin(), nums.end(), 0LL) - x;
        const int n = static_cast<int>(nums.size());

        if (target < 0)  return -1;
        if (target == 0) return n;
        long long window = 0;
        int best = -1;
        for (int lo = 0, hi = 0; hi < n; ++hi) {
            window += nums[hi];
            while (window > target)
                window -= nums[lo++];
            if (window == target)
                best = max(best, hi - lo + 1);
        }

        return best < 0 ? -1 : n - best;
    }
};