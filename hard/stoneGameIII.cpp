// Stone Game III

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();

        int next1 = 0, next2 = 0, next3 = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            int sum = stoneValue[i];
            
            int curr = sum - next1;
            
            if (i + 1 < n) {
                sum += stoneValue[i + 1];
                curr = std::max(curr, sum - next2);
                
                if (i + 2 < n) {
                    sum += stoneValue[i + 2];
                    curr = std::max(curr, sum - next3);
                }
            }
            
            next3 = next2;
            next2 = next1;
            next1 = curr;
        }
        
        if (next1 > 0) return "Alice";
        if (next1 < 0) return "Bob";
        return "Tie";
    }
};