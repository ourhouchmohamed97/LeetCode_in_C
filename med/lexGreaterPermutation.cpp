// Lexicographically Smallest Permutation Greater Than Target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<int> remain = cnt;
        int best = -1;

        for (int i = 0; i < n; i++) {
            int tc = target[i] - 'a';
            for (int c = tc + 1; c < 26; c++) {
                if (remain[c] > 0) { best = i; break; }
            }
            if (remain[tc] == 0) break;
            remain[tc]--;
        }

        if (best == -1) return "";

        remain = cnt;
        for (int i = 0; i < best; i++) remain[target[i] - 'a']--;

        string ans;
        ans.reserve(n);
        ans.assign(target, 0, best);

        int tc = target[best] - 'a';
        for (int c = tc + 1; c < 26; c++) {
            if (remain[c] > 0) {
                ans.push_back('a' + c);
                remain[c]--;
                break;
            }
        }
        for (int x = 0; x < 26; x++)
            ans.append(remain[x], 'a' + x);

        return ans;
    }
};