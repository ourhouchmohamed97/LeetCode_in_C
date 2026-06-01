// Count the Number of Special Characters II

#include <string.h>

int numberOfSpecialChars(char* word) {
    int first_upper[26];
    int last_lower[26];
    
    for (int i = 0; i < 26; i++) {
        first_upper[i] = -1;
        last_lower[i] = -1;
    }
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            int idx = word[i] - 'A';
            if (first_upper[idx] == -1) {
                first_upper[idx] = i;
            }
        }
    }
    
    int len = strlen(word);
    for (int i = len - 1; i >= 0; i--) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            int idx = word[i] - 'a';
            if (last_lower[idx] == -1) {
                last_lower[idx] = i;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
            count++;
        }
    }
    
    return count;
}
