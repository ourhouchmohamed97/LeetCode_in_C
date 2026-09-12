// Maximum Score of Non-overlapping Intervals

#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int, int, int, int>> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][1], intervals[i][0], intervals[i][2], i};
        }
    
        sort(sorted_intervals.begin(), sorted_intervals.end());
        
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = get<0>(sorted_intervals[i]);
        }
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 4; ++j) {
                dp[i][j].second.reserve(4);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int end, start, weight, idx;
            tie(end, start, weight, idx) = sorted_intervals[i];

            int k = lower_bound(ends.begin(), ends.begin() + i, start) - ends.begin();
            
            for (int j = 1; j <= 4; ++j) {
                dp[i + 1][j] = dp[i][j];

                long long take_weight = dp[k][j - 1].first - (long long)weight;
                vector<int> take_indices = dp[k][j - 1].second;
                auto pos = lower_bound(take_indices.begin(), take_indices.end(), idx);
                take_indices.insert(pos, idx);
                
                pair<long long, vector<int>> take = {take_weight, take_indices};
                
                // std::pair comparison natively acts like Python's tuple comparison
                if (take < dp[i + 1][j]) {
                    dp[i + 1][j] = take;
                }
            }
        }
        
        return dp[n][4].second;
    }
};