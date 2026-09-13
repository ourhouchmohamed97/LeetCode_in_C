// Image Overlap

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        
        vector<pair<int, int>> ones1, ones2;
        ones1.reserve(n * n);
        ones2.reserve(n * n);
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c])
                    ones1.emplace_back(r, c);
                if (img2[r][c])
                    ones2.emplace_back(r, c);
            }
        }
        const int size = 2 * n - 1;
        const int offset = n - 1;
        vector<int> freq(size * size, 0);
        int maxOverlap = 0;
        
        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int idx = (r1 - r2 + offset) * size + (c1 - c2 + offset);
                int val = ++freq[idx];
                if (val > maxOverlap)
                    maxOverlap = val;
            }
        } 
        return maxOverlap;
    }
};