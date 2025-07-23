// Maximum Score From Removing Substrings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeSubstring(char *s, char first, char second, int score) {
    int len = strlen(s);
    char *stack = (char *)malloc((len + 1) * sizeof(char));
    int top = -1;
    int points = 0;
    
    for (int i = 0; i < len; i++) {
        if (top >= 0 && stack[top] == first && s[i] == second) {
            top--;
            points += score;
        } else {
            stack[++top] = s[i];
        }
    }
    
    stack[++top] = '\0';
    strcpy(s, stack);
    free(stack);
    return points;
}

int maximumGain(char* s, int x, int y) {
    char *s_copy = strdup(s);
    int total = 0;
    
    if (x >= y) {
        total += removeSubstring(s_copy, 'a', 'b', x);
        total += removeSubstring(s_copy, 'b', 'a', y);
    } else {
        total += removeSubstring(s_copy, 'b', 'a', y);
        total += removeSubstring(s_copy, 'a', 'b', x);
    }
    
    free(s_copy);
    return total;
}

int main() {
    char s1[] = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    printf("Test Case 1: %d\n", maximumGain(s1, x1, y1)); // Expected: 19

    char s2[] = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    printf("Test Case 2: %d\n", maximumGain(s2, x2, y2)); // Expected: 20

    char s3[] = "ab";
    int x3 = 3, y3 = 2;
    printf("Test Case 3: %d\n", maximumGain(s3, x3, y3)); // Expected: 3

    char s4[] = "aaabbb";
    int x4 = 1, y4 = 1;
    printf("Test Case 4: %d\n", maximumGain(s4, x4, y4)); // Expected: 0

    char s5[] = "ababba";
    int x5 = 2, y5 = 3;
    printf("Test Case 5: %d\n", maximumGain(s5, x5, y5)); // Expected: 7

    return 0;
}