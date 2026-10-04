// Valid Parenthesis String

class Solution {
public:
    bool checkValidString(const string& s) {
        int lo = 0, hi = 0;
        
        for (char c : s) {
            if (c == '(') {
                ++lo; ++hi;
            } else if (c == ')') {
                --lo; --hi;
            } else {
                --lo; ++hi;
            }
            
            if (hi < 0) return false;
            if (lo < 0) lo = 0;
        }
        
        return lo == 0;
    }
};