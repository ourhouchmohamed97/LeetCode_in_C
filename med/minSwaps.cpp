// Minimum Swaps to Sort by Digit Sum

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto digit_sum = [](int x) {
            int s = 0;
            for (; x > 0; x /= 10) s += x % 10;
            return s;
        };
        int n = nums.size();
        vector<pair<int, int>> keyed;  // (digit sum, value)
        for (int x : nums) keyed.emplace_back(digit_sum(x), x);
        ranges::sort(keyed);
        unordered_map<int, int> rank;  // final position of each value
        for (int k = 0; k < n; k++) rank[keyed[k].second] = k;
        vector<int> home;  // where the value at each position must go
        for (int x : nums) home.push_back(rank[x]);

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            while (home[i] != i) {  // send the value at i home, take that spot's value in exchange
                int j = home[i];
                swap(home[i], home[j]);
                swaps++;
            }
        }
        return swaps;
    }
};