// Maximize Sum of Squares of Digits

#include <string>

class Solution {
public:
    std::string maxSumOfSquares(int num, int digit_sum) {
        if (digit_sum < 1 || digit_sum > 9 * num) {
            return "";
        }

        int nines = digit_sum / 9;
        int remainder = digit_sum % 9;

        std::string res(nines, '9');
        
        if (remainder > 0) {
            res.push_back(remainder + '0');
        }
        
        res.append(num - res.length(), '0');
        
        return res;
    }
};