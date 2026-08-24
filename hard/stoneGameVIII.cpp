// Stone Game VIII

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        std::partial_sum(stones.begin(), stones.end(), stones.begin());
        
        int best = stones.back();
        
        for (int i = n - 2; i >= 1; --i) {
            best = std::max(best, stones[i] - best);
        }
        
        return best;
    }
};