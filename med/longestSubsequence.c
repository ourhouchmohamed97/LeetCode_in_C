// Longest Binary Subsequence Less Than or Equal to K

#include <stdio.h>
#include <string.h>

int longestSubsequence(char* s, int k) {
    int res = 0, cost = 1, n = strlen(s);
    long long val = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            res++;
        } else {
            if (val + cost <= k) {
                val += cost;
                res++;
            }
        }
        if (cost <= k) {
            cost <<= 1;
        }
    }
    return res;
}

int main() {
    char s[] = "1001010";
    int k = 5;
    int result = longestSubsequence(s, k);
    printf("Longest subsequence length: %d\n", result);
    return 0;
}