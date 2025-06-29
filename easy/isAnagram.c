// Valid Anagram

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if (len_s != len_t)
        return false;
    
    int count[26] = {0};
    
    for (int i = 0; i < len_s; i++) {
        count[s[i] - 'a']++;
    }
    
    for (int i = 0; i < len_t; i++) {
        count[t[i] - 'a']--;
        if (count[t[i] - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char s[] = "anagram";
    char t[] = "nagaram";
    if (isAnagram(s, t)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    return 0;
}