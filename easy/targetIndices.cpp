// Find Target Indices After Sorting Array

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int x : nums) {
            less  += (x <  target);
            equal += (x == target);
        }
        vector<int> result(equal);
        iota(result.begin(), result.end(), less);
        return result;
    }
};
