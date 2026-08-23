// Sum Game

class Solution {
public:
    bool sumGame(const string& num) {
        int half = num.size() / 2;
        int sumDiff = 0;
        int qDiff = 0;
        
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') {
                ++qDiff;
            } else {
                sumDiff += num[i] - '0';
            }
            
            if (num[i + half] == '?') {
                --qDiff;
            } else {
                sumDiff -= num[i + half] - '0';
            }
        }
        
        return sumDiff * 2 != -qDiff * 9;
    }
};