// Score of Parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char ch : s) {
            if (ch == '(') {
                st.push(0);
            } else {
                int v = st.top(); st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};