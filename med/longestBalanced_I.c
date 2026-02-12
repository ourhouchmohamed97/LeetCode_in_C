// Longest Balanced Substring I

#include <string.h>

int longestBalanced(char* s) {
    int n = strlen(s);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int freq[26] = {0};
        int max = 0;
        int cnt = 0;

        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            
            if (freq[idx] == 0) {
                cnt++;
            }
            
            freq[idx]++;
            if (freq[idx] > max) {
                max = freq[idx];
            }
            
            int curr = j - i + 1;
            
            if (max * cnt == curr) {
                ans = fmax(ans, curr);
            }
        }
    }
    return ans;
}