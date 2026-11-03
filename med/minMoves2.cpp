// Minimum Moves to Equal Array Elements II

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        const int med = *mid;           
        long long moves = 0;
        for (int x : nums)
            moves += abs(1LL * x - med);  
        return static_cast<int>(moves);
    }
};