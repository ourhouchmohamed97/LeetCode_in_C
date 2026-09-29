// Check if There Is a Valid Parentheses String Path

class Solution {
    static constexpr int W = 128;
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        const int L = m + n - 1;
        if (L % 2 != 0) return false;
        if (grid[0][0] != '(' || grid[m-1][n-1] != ')') return false;

        const int B = L / 2 + 1;
        const bitset<W> mask = ~bitset<W>(0) >> (W - B);

        vector<bitset<W>> up(n), cur(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) { cur[0] = 0b10; continue; }
                bitset<W> s = up[j] | (j ? cur[j-1] : bitset<W>(0));
                cur[j] = grid[i][j] == '(' ? (s << 1) & mask : s >> 1;
            }
            swap(up, cur);
        }
        return up[n-1][0];
    }
};