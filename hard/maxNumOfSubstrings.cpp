// Maximum Number of Non-Overlapping Substrings

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        int first[26], last[26];
        for (int i = 0; i < 26; i++) { first[i] = n; last[i] = -1; }
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (i < first[c]) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals;
        intervals.reserve(26);
        for (int c = 0; c < 26; c++) {
            if (last[c] < 0) continue;
            int l = first[c], r = last[c];
            bool valid = true;
            for (int i = l; i <= r && valid; i++) {
                int x = s[i] - 'a';
                if (first[x] < l) valid = false;
                else if (last[x] > r) r = last[x];
            }
            if (valid) intervals.emplace_back(r, l);
        }
        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prevEnd = -1;
        for (auto [r, l] : intervals) {
            if (l > prevEnd) {
                ans.emplace_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        return ans;
    }
};