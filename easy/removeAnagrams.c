// Find Resultant Array After Removing Anagrams

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(const char *a, const char *b) {
    if (strlen(a) != strlen(b))
        return false;
    int count[26] = {0};
    for (int i = 0; a[i]; i++) {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return false;
    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (idx == 0 || !isAnagram(words[i], res[idx - 1])) {
            res[idx] = strdup(words[i]);
            idx++;
        }
    }
    *returnSize = idx;
    return res;
}

int main() {
    char* words[] = {"abba", "baba", "bbaa", "cd", "cd"};
    int size = 5;
    int returnSize;
    char** result = removeAnagrams(words, size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);
    printf("\n");
    return 0;
}
