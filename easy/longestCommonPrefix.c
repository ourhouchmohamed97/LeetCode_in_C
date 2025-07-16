// Longest Common Prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    char* prefix = strs[0];
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (prefix[0] == '\0') {
            break;
        }
    }
    
    char* result = (char*)malloc(strlen(prefix) + 1);
    strcpy(result, prefix);
    return result;
}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    char* result1 = longestCommonPrefix(strs1, size1);
    printf("Test case 1: \"%s\"\n", result1);  // Expected output: "fl"
    free(result1);
    
    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = 3;
    char* result2 = longestCommonPrefix(strs2, size2);
    printf("Test case 2: \"%s\"\n", result2);  // Expected output: ""
    free(result2);
    
    char* strs3[] = {"interspecies", "interstellar", "interstate"};
    int size3 = 3;
    char* result3 = longestCommonPrefix(strs3, size3);
    printf("Test case 3: \"%s\"\n", result3);  // Expected output: "inters"
    free(result3);
    
    char* strs4[] = {"", "flow", "flight"};
    int size4 = 3;
    char* result4 = longestCommonPrefix(strs4, size4);
    printf("Test case 4: \"%s\"\n", result4);  // Expected output: ""
    free(result4);
    
    return 0;
}