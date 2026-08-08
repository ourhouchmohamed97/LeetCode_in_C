// Find the Lexicographically Smallest Valid Sequence

#include <string>
#include <vector>

class Solution {
public:
    vector<int> validSequence(string s, string t) {
        const int n = s.size();
        const int m = t.size();
        
        if (n < m) return {};
        
        vector<int> dp(n + 1, 0);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (j >= 0 && s[i] == t[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            } else {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> ans;
        ans.reserve(m);
        bool usedMismatch = false;
        int j = 0;
        
        for (int i = 0; i < n && j < m; i++) {
            if (s[i] == t[j]) {
                ans.push_back(i);
                j++;
            } else if (!usedMismatch && dp[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                usedMismatch = true;
            }
        }

        return j == m ? ans : vector<int>{};
    }
};