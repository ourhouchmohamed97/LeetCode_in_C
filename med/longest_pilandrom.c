// Longest Palindromic Substring 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expandAroundCenter(char *s, int left, int right, int *start, int *maxLen) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    int currentLen = right - left - 1;
    if (currentLen > *maxLen) {
        *maxLen = currentLen;
        *start = left + 1;
    }
}

char *longestPalindrome(char *s) {
    if (s == NULL || strlen(s) < 1) return "";
    int start = 0, maxLen = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        expandAroundCenter(s, i, i, &start, &maxLen);
        expandAroundCenter(s, i, i + 1, &start, &maxLen);
    }
    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}

int main() {
    char s1[] = "babad";
    char *result1 = longestPalindrome(s1);
    printf("%s\n", result1); // Output: "bab" or "aba"
    free(result1);

    char s2[] = "cbbd";
    char *result2 = longestPalindrome(s2);
    printf("%s\n", result2); // Output: "bb"
    free(result2);

    return 0;
}