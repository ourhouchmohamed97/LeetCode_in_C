// Shortest and Lexicographically Smallest Beautiful String

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> ones;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') ones.push_back(i);

        if ((int)ones.size() < k) return "";

        int bestLen = n + 1, bestStart = 0;
        for (int i = 0; i + k <= (int)ones.size(); i++) {
            int len = ones[i + k - 1] - ones[i] + 1;
            if (len < bestLen ||
                (len == bestLen && s.compare(ones[i], len, s, bestStart, len) < 0)) {
                bestLen = len;
                bestStart = ones[i];
            }
        }
        return s.substr(bestStart, bestLen);
    }
};