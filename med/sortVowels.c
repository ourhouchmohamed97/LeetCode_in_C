// Sort Vowels in a String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char* sortVowels(char* s) {
    int n = strlen(s);
    
    char *vowels = (char*)malloc(n * sizeof(char));
    int vcount = 0;
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            vowels[vcount++] = s[i];
        }
    }
    
    qsort(vowels, vcount, sizeof(char), cmp);
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            s[i] = vowels[idx++];
        }
    }
    
    free(vowels);
    return s;
}

int main() {
    char s1[] = "lEetcOde";
    char s2[] = "lYmpH";
    
    printf("%s\n", sortVowels(s1)); // Output: lEOtcede
    printf("%s\n", sortVowels(s2)); // Output: lYmpH
    
    return 0;
}
