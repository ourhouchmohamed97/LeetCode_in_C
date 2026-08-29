// Make Lexicographically Smallest Array by Swapping Elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                ++j;
            }
            
            vector<int> origIdx(idx.begin() + i, idx.begin() + j + 1);
            sort(origIdx.begin(), origIdx.end());
            
            for (int k = 0; k + i <= j; ++k) {
                result[origIdx[k]] = nums[idx[i + k]];
            }
            
            i = j + 1;
        }
        
        return result;
    }
};