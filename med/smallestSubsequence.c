// Smallest Subsequence of Distinct Characters

#include <stdbool.h>

char* smallestSubsequence(char* s) {
    int freq[128] = {0};
    bool visited[128] = {false};

    int n = strlen(s);
    char* stack = malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        freq[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < n; i++) {
        char c = s[i];
        freq[(unsigned char)c]--;

        if (visited[(unsigned char)c]) {
            continue;
        }

        while (
            top > 0 &&
            stack[top - 1] > c &&
            freq[(unsigned char)stack[top - 1]] > 0
        ) {
            visited[(unsigned char)stack[top - 1]] = false;
            top--;
        }

        stack[top++] = c;
        visited[(unsigned char)c] = true;
    }

    stack[top] = '\0';
    return stack;
}