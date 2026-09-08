// Count Commas in Range

class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long lower = 1000;
        int commas = 1;
        
        while (lower <= n) {
            long long upper = lower * 1000 - 1;
            long long count = std::min((long long)n, upper) - lower + 1;
            total += count * commas;
            lower *= 1000;
            commas++;
        }
        
        return static_cast<int>(total);
    }
};