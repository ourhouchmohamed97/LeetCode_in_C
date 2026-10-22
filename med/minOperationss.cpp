// Minimum Operations to Sort a Permutation

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int shift = ranges::find(nums, 0) - nums.begin();

        auto ring = [&](int k) -> int { return nums[(shift + k) % n]; };

        auto check = [&](auto pred) {
            return ranges::all_of(views::iota(0, n), pred);
        };

        bool forward  = check([&](int k) { return ring(k) == k; });
        bool backward = check([&](int k) { return ring(k) == (n - k) % n; });

        if (forward)  return min(shift, n - shift + 2);
        if (backward) return min(shift + 2, n - shift);
        return -1;
    }
};
