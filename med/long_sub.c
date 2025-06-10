// Longest Substring Without Repeating Characters

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s)
{
    int n = strlen(s);
    if (n == 0)
        return 0;
    
    int charIndex[256];
    memset(charIndex, -1, sizeof(charIndex));
    
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < n; end++)
    {
        char currentChar = s[end];

        if (charIndex[currentChar] >= start)
            start = charIndex[currentChar] + 1;

        charIndex[currentChar] = end;

        int currentLength = end - start + 1;

        if (currentLength > maxLength)
            maxLength = currentLength;
    }
    
    return (maxLength);
}


int main() {
    char s[] = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    // Output must be 3
    printf("Length of the longest substring without repeating characters: %d\n", length);
    return 0;
}