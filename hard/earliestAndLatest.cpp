// The Earliest and Latest Rounds Where Players Compete

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
 public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    using P = pair<int, int>;
    vector<vector<vector<P>>> mem(n + 1,
                                  vector<vector<P>>(n + 1, vector<P>(n + 1)));
    const auto [a, b] = solve(firstPlayer, n - secondPlayer + 1, n, mem);
    return {a, b};
  }

 private:
  pair<int, int> solve(int l, int r, int k,
                       vector<vector<vector<pair<int, int>>>>& mem) {
    if (l == r)
      return {1, 1};
    if (l > r)
      swap(l, r);
    if (mem[l][r][k] != pair<int, int>{0, 0})
      return mem[l][r][k];

    int a = INT_MAX;
    int b = INT_MIN;

    for (int i = 1; i <= l; ++i)
      for (int j = l - i + 1; j <= r - i; ++j) {
        if (i + j > (k + 1) / 2 || i + j < l + r - k / 2)
          continue;
        const auto [x, y] = solve(i, j, (k + 1) / 2, mem);
        a = min(a, x + 1);
        b = max(b, y + 1);
      }

    return mem[l][r][k] = {a, b};
  }
};

int main() {
  Solution sol;

  int n = 11;
  int firstPlayer = 2;
  int secondPlayer = 4;

  vector<int> result = sol.earliestAndLatest(n, firstPlayer, secondPlayer);

  cout << "Earliest round: " << result[0] << endl;
  cout << "Latest round: " << result[1] << endl;

  return 0;
}
