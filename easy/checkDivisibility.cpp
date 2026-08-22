// Check Divisibility by Digit Sum and Product

class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        
        for (int temp = n; temp > 0; temp /= 10) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
        }
        
        return n % (digitSum + digitProduct) == 0;
    }
};