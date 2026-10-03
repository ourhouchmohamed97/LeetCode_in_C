// Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(const string& s) {
        int res = 0;
        vector<int> idx;
        idx.reserve(s.size() + 1);
        idx.push_back(-1);
        
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                idx.push_back(i);
            } else {
                idx.pop_back();
                if (idx.empty()) {
                    idx.push_back(i);
                } else {
                    res = max(res, i - idx.back());
                }
            }
        }
        return res;
    }
};