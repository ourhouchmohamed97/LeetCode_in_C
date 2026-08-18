// Find the Largest Almost Missing Integer

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        int freq[51] = {};
        for (const int num : nums) {
            ++freq[num];
        }

        int result = -1;
        for (int i = 0; i < n; ++i) {
            const int val = nums[i];
            const bool isUnique = (freq[val] == 1);
            const bool isAtEndpoint = (i == 0 || i == n - 1);
            
            if (isUnique && (k == 1 || isAtEndpoint)) {
                result = std::max(result, val);
            }
        }

        return result;
    }
};