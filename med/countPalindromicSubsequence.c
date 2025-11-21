// Unique Length-3 Palindromic Subsequences

int countPalindromicSubsequence(char* s) {
    int n = strlen(s);
    int first[26], last[26];
    
    for (int i = 0; i < 26; i++) {
        first[i] = n;
        last[i] = -1;
    }

    // find first and last occurrences
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (i < first[c]) first[c] = i;
        last[c] = i;
    }

    int res = 0;

    for (int c = 0; c < 26; c++) {
        int L = first[c];
        int R = last[c];
        if (R - L < 2) continue;

        int memo[26] = {0};

        for (int i = L + 1; i < R; i++) {
            int idx = s[i] - 'a';
            if (!memo[idx]) {
                memo[idx] = 1;
                res++;
            }
        }
    }

    return res;
}