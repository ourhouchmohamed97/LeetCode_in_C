// Number of Ways to Divide a Long Corridor

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long s0 = 0, s1 = 0, s2 = 1;  // 0, 1 or 2 seats in current segment
        for (char c : corridor) {
            if (c == 'S') s0 = s1, swap(s1, s2);
            else s2 = (s2 + s0) % mod;
        }
        return s0;
    }
};