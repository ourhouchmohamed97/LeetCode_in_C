// Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};