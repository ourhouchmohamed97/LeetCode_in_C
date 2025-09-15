// Vowel Spellchecker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VOWEL(c) (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')

// Hash map entry
typedef struct {
    char *key;      // key string
    char *value;    // mapped word
} HashMap;

char *toLowerStr(const char *s) {
    int n = strlen(s);
    char *res = malloc(n+1);
    for (int i = 0; i < n; i++)
        res[i] = tolower((unsigned char)s[i]);
    res[n] = '\0';
    return res;
}

char *devowelStr(const char *s) {
    int n = strlen(s);
    char *res = malloc(n+1);
    for (int i = 0; i < n; i++) {
        char c = tolower((unsigned char)s[i]);
        res[i] = VOWEL(c) ? '*' : c;
    }
    res[n] = '\0';
    return res;
}

char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    char **ans = calloc(queriesSize, sizeof(char*));

    HashMap *exactMap = NULL;
    HashMap *caseMap = NULL;
    HashMap *vowelMap = NULL;

    // Preprocess wordlist
    for (int i = 0; i < wordlistSize; i++) {
        char *w = wordlist[i];

        // 1. exact map
        HashMap *entry;
        HASH_FIND_STR(exactMap, w, entry);
        if (!entry) {
            entry = malloc(sizeof(HashMap));
            entry->key = strdup(w);
            entry->value = w;
            HASH_ADD_KEYPTR(exactMap, entry->key, strlen(entry->key), entry);
        }

        // 2. case-insensitive map
        char *low = toLowerStr(w);
        HASH_FIND_STR(caseMap, low, entry);
        if (!entry) {
            entry = malloc(sizeof(HashMap));
            entry->key = low;
            entry->value = w;
            HASH_ADD_KEYPTR(caseMap, entry->key, strlen(entry->key), entry);
        } else {
            free(low);
        }

        // 3. vowel-error map
        char *dev = devowelStr(w);
        HASH_FIND_STR(vowelMap, dev, entry);
        if (!entry) {
            entry = malloc(sizeof(HashMap));
            entry->key = dev;
            entry->value = w;
            HASH_ADD_KEYPTR(vowelMap, entry->key, strlen(entry->key), entry);
        } else {
            free(dev);
        }
    }

    // Answer queries
    for (int i = 0; i < queriesSize; i++) {
        char *q = queries[i];
        HashMap *entry;

        // 1. exact match
        HASH_FIND_STR(exactMap, q, entry);
        if (entry) {
            ans[i] = strdup(entry->value);
            continue;
        }

        // 2. case-insensitive
        char *low = toLowerStr(q);
        HASH_FIND_STR(caseMap, low, entry);
        if (entry) {
            ans[i] = strdup(entry->value);
            free(low);
            continue;
        }
        free(low);

        // 3. vowel-error
        char *dev = devowelStr(q);
        HASH_FIND_STR(vowelMap, dev, entry);
        if (entry) {
            ans[i] = strdup(entry->value);
            free(dev);
            continue;
        }
        free(dev);

        // 4. no match
        ans[i] = strdup("");
    }

    return ans;
}

// ---------------------- TESTING MAIN ----------------------
int main() {
    char *wordlist[] = {"KiTe","kite","hare","Hare"};
    int wordlistSize = 4;

    char *queries[] = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    int queriesSize = 10;

    int returnSize;
    char **result = spellchecker(wordlist, wordlistSize, queries, queriesSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(",");
        free(result[i]); // cleanup
    }
    printf("]\n");

    free(result);
    return 0;
}
