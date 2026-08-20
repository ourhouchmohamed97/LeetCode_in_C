// Distribute Elements Into Two Arrays I

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> A{nums[0]}, B{nums[1]};
        A.reserve(n);
        B.reserve(n);
        for (int i = 2; i < n; ++i) {
            (A.back() > B.back() ? A : B).push_back(nums[i]);
        }
        A.insert(A.end(),
                 make_move_iterator(B.begin()),
                 make_move_iterator(B.end()));
        return A;
    }
};