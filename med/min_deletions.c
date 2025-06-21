// Minimum Deletions to Make String K-Special

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minDeletionsToKSpecial(char* word, int k) {
    int freq[26] = {0};
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        freq[word[i] - 'a']++;
    }
    
    int frequencies[26];
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            frequencies[count++] = freq[i];
        }
    }
    
    qsort(frequencies, count, sizeof(int), cmp);
    
    int min_deletions = INT_MAX;
    
    for (int i = 0; i < count; i++) {
        int target = frequencies[i];
        int upper = target + k;
        int deletions = 0;
        
        for (int j = 0; j < count; j++) {
            if (frequencies[j] < target) {
                deletions += frequencies[j];
            } else if (frequencies[j] > upper) {
                deletions += frequencies[j] - upper;
            }
        }
        
        if (deletions < min_deletions) {
            min_deletions = deletions;
        }
    }
    
    return min_deletions;
}

int main() {
    char word1[] = "aabcaba";
    int k1 = 0;
    printf("%d\n", minDeletionsToKSpecial(word1, k1)); // Output: 3
    
    char word2[] = "dabdcbdcdcd";
    int k2 = 2;
    printf("%d\n", minDeletionsToKSpecial(word2, k2)); // Output: 2
    
    char word3[] = "aaabaaa";
    int k3 = 2;
    printf("%d\n", minDeletionsToKSpecial(word3, k3)); // Output: 1
    
    return 0;
}