// Number of Sets of K Non-Overlapping Line Segments

 class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<long long> prev(n, 1);
        vector<long long> curr(n, 0);

        for (int j = 1; j <= k; ++j) {
            long long sum = 0;
            curr[0] = 0;
            for (int i = 1; i < n; ++i) {
                sum = (sum + prev[i - 1]) % MOD;
                curr[i] = (curr[i - 1] + sum) % MOD;
            }
            swap(prev, curr);
        }
        return prev[n - 1];
    }
};