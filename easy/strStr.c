// Find the Index of the First Occurrence in a String

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if (needleLen == 0)
        return 0;
    if (haystackLen < needleLen)
        return -1;
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == needleLen)
            return i;
    }
    
    return -1;
}

int main() {
    char* haystack1 = "sadbutsad";
    char* needle1 = "sad";
    int result1 = strStr(haystack1, needle1);
    printf("Example 1 Output: %d\n", result1);
    
    char* haystack2 = "leetcode";
    char* needle2 = "leeto";
    int result2 = strStr(haystack2, needle2);
    printf("Example 2 Output: %d\n", result2);
    
    char* haystack3 = "hello";
    char* needle3 = "ll";
    int result3 = strStr(haystack3, needle3);
    printf("Additional Example Output: %d\n", result3);
    
    return 0;
}