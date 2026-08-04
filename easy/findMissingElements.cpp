// Find Missing Elements

#include <vector>

class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> hasX=0;
        int xMin=101, xMax=0;
        for(int x: nums){
            hasX[x]=1;
            xMin=min(x, xMin);
            xMax=max(x, xMax);
        }
        vector<int> ans;
        for(int x=xMin+1; x<xMax; x++)
            if (!hasX[x]) ans.push_back(x);
        return ans;
    }
};