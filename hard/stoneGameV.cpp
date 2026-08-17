// stone Game V

int dp[501][501];
int Sum[501];

class Solution {
public:
    static int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        partial_sum(stoneValue.begin(), stoneValue.end(), Sum + 1);
        
        memset(dp, 0, sizeof(dp)); 
        
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                int ans = 0;
                
                for (int m = l; m < r; ++m) {
                    int Lsum = Sum[m + 1] - Sum[l];
                    int Rsum = Sum[r + 1] - Sum[m + 1];
                    
                    if (Lsum <= Rsum) ans = max(ans, Lsum + dp[l][m]);
                    if (Lsum >= Rsum) ans = max(ans, Rsum + dp[m + 1][r]);
                    
                    if (2 * min(Lsum, Rsum) <= ans) break;
                }
                dp[l][r] = ans;
            }
        }
        return dp[0][n - 1];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();