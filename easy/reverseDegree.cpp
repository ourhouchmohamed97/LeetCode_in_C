// Reverse Degree of a String

class Solution {
public:
    int reverseDegree(const string& s) {
        int sum = 0;
        int pos = 1;
        for (char c : s) {
            sum += ('z' - c + 1) * pos;
            ++pos;
        }
        return sum;
    }
};