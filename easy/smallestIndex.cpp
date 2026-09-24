// Smallest Index With Digit Sum Equal to Index

class Solution {
    static constexpr int kMaxFeasibleIndex = 28;

    static int digitSum(int x) {
        int s = 0;
        for (; x > 0; x /= 10) s += x % 10;
        return s;
    }

public:
    int smallestIndex(vector<int>& nums) {
        const int bound = std::min<int>(kMaxFeasibleIndex, 
                                        static_cast<int>(nums.size()));
        for (int i = 0; i < bound; ++i) {
            if (digitSum(nums[i]) == i) return i;
        }
        return -1;
    }
};