// Distinct Subsequences II

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long long total = 0;            // Σ dp[j] over all processed j
        long long result = 0;
        long long charSum[26] = {0};    // Σ dp[j] where s[j] == c

        for (char c : s) {
            int idx = c - 'a';
            // dp[i] = 1 + (total) - (charSum[idx])
            long long dp_i = (1 + total - charSum[idx] + MOD) % MOD;
            total    = (total + dp_i) % MOD;
            charSum[idx] = (charSum[idx] + dp_i) % MOD;
            result   = (result + dp_i) % MOD;
        }
        return (int)result;
    }
};