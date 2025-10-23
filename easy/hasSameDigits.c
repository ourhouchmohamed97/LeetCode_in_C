// Check If Digits Are Equal in String After Operations I

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool hasSameDigits(char* s) {
    int len = strlen(s);
    while (len > 2) {
        for (int i = 0; i < len - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            s[i] = ((a + b) % 10) + '0';
        }
        len--;
        s[len] = '\0';
    }
    return s[0] == s[1];
}

int main() {
    char s1[] = "3902";
    char s2[] = "34789";
    printf("%s -> %s\n", s1, hasSameDigits(s1) ? "true" : "false");
    printf("%s -> %s\n", s2, hasSameDigits(s2) ? "true" : "false");
    return 0;
}
