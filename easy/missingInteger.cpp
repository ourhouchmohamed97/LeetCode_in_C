// Smallest Missing Integer Greater Than Sequential Prefix Sum

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1] + 1) break;
            sum += nums[i];
        }

        const unordered_set<int> seen(nums.begin(), nums.end());
        
        int answer = sum;
        while (seen.contains(answer)) {
            ++answer;
        }

        return answer;
    }
};