// Maximum Number of Events That Can Be Attended II

#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>

class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int k) {
    vector<vector<int>> mem(events.size(), vector<int>(k + 1, -1));
    ranges::sort(events);
    return maxValue(events, 0, k, mem);
  }

 private:
  int maxValue(const vector<vector<int>>& events, int i, int k,
               vector<vector<int>>& mem) {
    if (k == 0 || i == events.size())
      return 0;
    if (mem[i][k] != -1)
      return mem[i][k];

    const auto it = upper_bound(
        events.begin() + i, events.end(), events[i][1],
        [](int end, const vector<int>& event) { return event[0] > end; });
    const int j = distance(events.begin(), it);
    return mem[i][k] = max(events[i][2] + maxValue(events, j, k - 1, mem),
                           maxValue(events, i + 1, k, mem));
  }
};

int main() {
  Solution sol;
  vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
  int k = 2;
  int result = sol.maxValue(events, k);
  cout << result << endl; // Output: 7
  return 0;
}
