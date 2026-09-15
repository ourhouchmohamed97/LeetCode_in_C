// Maximum Number of Non-overlapping Palindrome Substrings

class Solution {
public:
    int maxPalindromes(string s, int k) {
        const int n = static_cast<int>(s.size());
        int res = 0;

        for (int i = 0; i + k <= n; ) {
            int len = 0;
            for (int d : {k, k + 1}) {
                if (i + d > n) continue;

                bool isPal = true;
                for (int l = i, r = i + d - 1; l < r; ++l, --r) {
                    if (s[l] != s[r]) { isPal = false; break; }
                }
                if (isPal) { len = d; break; }
            }

            if (len) { ++res; i += len; }
            else     { ++i; }
        }
        return res;
    }
};