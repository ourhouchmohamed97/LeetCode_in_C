// Valid Parentheses

class Solution {
public:
    bool isValid(const string& s) {
        if (s.size() % 2) return false;

        string stack;
        stack.reserve(s.size());

        for (char c : s) {
            switch (c) {
                case '(': case '[': case '{':
                    stack.push_back(c);
                    break;
                case ')':
                    if (stack.empty() || stack.back() != '(') return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || stack.back() != '[') return false;
                    stack.pop_back();
                    break;
                case '}':
                    if (stack.empty() || stack.back() != '{') return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};