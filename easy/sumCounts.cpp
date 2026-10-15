// Subarrays Distinct Element Sum of Squares I

#include <vector>
#include <bitset>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        const size_t n = nums.size();
        if (n == 0) return 0;
        
        int ans = 0;
        std::bitset<101> seen;
        
        for (size_t l = 0; l < n; ++l) {
            seen.reset();
            int cnt = 0;
            for (size_t r = l; r < n; ++r) {
                if (!seen.test(nums[r])) {
                    seen.set(nums[r]);
                    cnt++;
                }
                ans += cnt * cnt;
            } 
        }
        return ans;
    }
};