// Count Commas in Range II

class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        for (long long p = 1000; p <= n; ) {
            count += n - p + 1;
            if (p > LLONG_MAX / 1000) break;
            p *= 1000;
        }
        return count;
    }
};