// Rearranging Fruits

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int, int> countMap;

        for (int i = 0; i < n; ++i) {
            countMap[basket1[i]]++;
            countMap[basket2[i]]--;
        }

        int minFruit = INT_MAX;
        vector<int> disparities;

        for (auto& [fruit, count] : countMap) {
            if (count % 2) {
                return -1;
            }
          
            for (int i = abs(count) / 2; i > 0; --i) {
                disparities.push_back(fruit);
            }

            minFruit = min(minFruit, fruit);
        }

        sort(disparities.begin(), disparities.end());

        int m = disparities.size();
        long long totalCost = 0;

        for (int i = 0; i < m / 2; ++i) {
            totalCost += min(disparities[i], minFruit * 2);
        }

        return totalCost;
    }
};

int main() {
    Solution sol;
    vector<int> basket1 = {4, 2, 2, 2};
    vector<int> basket2 = {1, 4, 1, 2};
    long long result = sol.minCost(basket1, basket2);
    return 0;
}