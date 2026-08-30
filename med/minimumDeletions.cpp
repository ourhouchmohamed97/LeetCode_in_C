// Removing Minimum and Maximum From Array

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int lo = min(minIdx, maxIdx);
        int hi = max(minIdx, maxIdx);
        
        // Three strategies:
        // 1) Remove both from the front:        hi + 1
        // 2) Remove both from the back:         n - lo
        // 3) Remove lo from front, hi from back: (lo + 1) + (n - hi)
        return min({hi + 1, n - lo, lo + 1 + n - hi});
    }
};