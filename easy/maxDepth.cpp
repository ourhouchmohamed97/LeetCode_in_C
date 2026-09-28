// Maximum Nesting Depth of the Parentheses

class Solution {
public:
    int maxDepth(std::string_view s) {
        int depth = 0, result = 0;
        for (char c : s) {
            if (c == '(')      result = std::max(result, ++depth);
            else if (c == ')') --depth;
        }
        return result;
    }
};