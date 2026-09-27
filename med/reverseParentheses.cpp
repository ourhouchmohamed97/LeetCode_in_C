// Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        const int n = static_cast<int>(s.size());
        vector<int> match(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                const int j = st.top();
                st.pop();
                match[i] = j;
                match[j] = i;
            }
        }

        string res;
        res.reserve(n);
        for (int i = 0, dir = 1; i >= 0 && i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};