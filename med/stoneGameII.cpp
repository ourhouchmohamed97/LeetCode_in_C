// Stone Game II

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } else {
                    int minOpponentScore = INT_MAX;
                    for (int k = 1; k <= 2 * m; ++k) {
                        minOpponentScore = min(minOpponentScore, dp[i + k][max(m, k)]);
                    }
                    dp[i][m] = suffixSum[i] - minOpponentScore;
                }
            }
        }

        return dp[0][1];
    }
};
