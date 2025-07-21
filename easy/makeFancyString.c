// Delete Characters to Make Fancy String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateFancyLength(char *s) {
    int len = 0;
    for (int i = 0; s[i]; ) {
        char current = s[i];
        int count = 0;
        
        while (s[i] && s[i] == current) {
            count++;
            i++;
        }
        
        len += (count > 2) ? 2 : count;
    }
    return len;
}

char* makeFancyString(char* s) {
    int fancy_len = calculateFancyLength(s);
    char *new = malloc(fancy_len + 1);
    int j = 0;
    
    for (int i = 0; s[i]; ) {
        char current = s[i];
        int count = 0;
        
        while (s[i] && s[i] == current) {
            count++;
            i++;
        }
        
        int add = (count > 2) ? 2 : count;
        while (add-- > 0) {
            new[j++] = current;
        }
    }
    
    new[j] = '\0';
    return new;
}

int main() {
    char *test_cases[] = {
        "leeetcode",  // Expected: "leetcode"
        "aaabaaaa",   // Expected: "aabaa"
        "aab",        // Expected: "aab"
        "aaa",        // Expected: "aa"
        "aaaaaabbbcc",// Expected: "aabbcc"
        "x"           // Expected: "x"
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; i++) {
        char *input = test_cases[i];
        char *output = makeFancyString(input);
        
        printf("Input: \"%s\"\n", input);
        printf("Output: \"%s\"\n", output);
        printf("\n");
        
        free(output);
    }
    
    return 0;
}