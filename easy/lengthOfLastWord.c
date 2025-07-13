// Length of Last Word

#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int len = 0;
    int i = strlen(s) - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    
    return len;
}

int main() {
    char s1[] = "Hello World";
    printf("Example 1: \"%s\" -> %d\n", s1, lengthOfLastWord(s1));  // Output: 5
    
    char s2[] = "   fly me   to   the moon  ";
    printf("Example 2: \"%s\" -> %d\n", s2, lengthOfLastWord(s2));  // Output: 4
    
    char s3[] = "luffy is still joyboy";
    printf("Example 3: \"%s\" -> %d\n", s3, lengthOfLastWord(s3));  // Output: 6
    
    char s4[] = "SingleWord";
    printf("Additional Test 1: \"%s\" -> %d\n", s4, lengthOfLastWord(s4));  // Output: 10
    
    char s5[] = "TrailingSpaces   ";
    printf("Additional Test 2: \"%s\" -> %d\n", s5, lengthOfLastWord(s5));  // Output: 7
    
    return 0;
}