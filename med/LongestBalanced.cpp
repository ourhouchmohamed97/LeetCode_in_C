class Solution {
public:
    int longestBalanced(string s) {
        int results[7] = {
            solve1(s, 'a'),
            solve1(s, 'b'),
            solve1(s, 'c'),
            solve2(s, 'a', 'b'),
            solve2(s, 'a', 'c'),
            solve2(s, 'b', 'c'),
            solve3(s)
        };
        int ans = 0;
        for (int v : results) ans = max(ans, v);
        return ans;
    }

private:
    int solve1(const string& s, char t) {
        int result = 0;
        int count = 0;
        for (char c : s) {
            if (c == t) {
                count++;
                result = max(result, count);
            } else {
                count = 0;
            }
        }
        return result;
    }

    int solve2(const string& s, char t1, char t2) {
        int result = 0;
        int counts[2] = {0, 0};
        unordered_map<int, int> previousPositions;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (c != t1 && c != t2) {
                previousPositions.clear();
                counts[0] = 0;
                counts[1] = 0;
            } else {
                if (c == t1) counts[0]++; else counts[1]++;
                if (counts[0] == counts[1]) {
                    result = max(result, counts[0] * 2);
                } else {
                    int diff = counts[0] - counts[1];
                    auto it = previousPositions.find(diff);
                    if (it != previousPositions.end()) {
                        result = max(result, i - it->second);
                    } else {
                        previousPositions[diff] = i;
                    }
                }
            }
        }
        return result;
    }

    int solve3(const string& s) {
        int result = 0;
        int counts[3] = {0, 0, 0};
        unordered_map<long long, int> previousPositions;
        for (int i = 0; i < (int)s.size(); i++) {
            counts[s[i] - 'a']++;
            if (counts[0] == counts[1] && counts[1] == counts[2]) {
                result = i + 1;
            } else {
                long long diff = (long long)(counts[0] - counts[1]) * 100001LL + (long long)(counts[1] - counts[2]);
                auto it = previousPositions.find(diff);
                if (it != previousPositions.end()) {
                    result = max(result, i - it->second);
                } else {
                    previousPositions[diff] = i;
                }
            }
        }
        return result;
    }
};