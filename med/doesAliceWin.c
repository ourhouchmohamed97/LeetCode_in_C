// Vowels Game in a String

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool doesAliceWin(char* s) {
    if (!s) return (false);
    for (char *p = s; *p; ++p) {
        char c = tolower((unsigned char)*p);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return (true);
    }
    return (false);
}

int main(void) {
    char s1[] = "leetcoder";
    char s2[] = "bbcd";

    printf("Input: %s -> %s\n", s1, doesAliceWin(s1) ? "true" : "false");
    printf("Input: %s -> %s\n", s2, doesAliceWin(s2) ? "true" : "false");

    return 0;
}
