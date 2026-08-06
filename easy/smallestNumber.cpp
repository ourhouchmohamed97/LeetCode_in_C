// Smallest Divisible Digit Product I

class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;
        while (true) {
            if (digitProduct(num) % t == 0) {
                return num;
            }
            num++;
        }
    }

private:
    int digitProduct(int num) {
        int prod = 1;
        while (num > 0) {
            prod *= num % 10;
            num /= 10;
        }
        return prod;
    }
};