// Generate Parentheses

class Solution { 
public: 
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        ans.reserve(1 << (2 * n - 1));
        string cur;
        cur.reserve(2 * n);
        
        function<void(int,int)> dfs = [&](int open, int close) {
            if (open == 0 && close == 0) {
                ans.push_back(cur);
                return;
            }
            if (open > 0) {
                cur.push_back('(');
                dfs(open - 1, close);
                cur.pop_back();
            }
            if (close > open) {
                cur.push_back(')');
                dfs(open, close - 1);
                cur.pop_back();
            }
        };
        dfs(n, n);
        return ans;
    } 
};