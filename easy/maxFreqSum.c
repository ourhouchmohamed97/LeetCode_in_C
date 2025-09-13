// Find Most Frequent Vowel and Consonant

#include <stdio.h>
#include <string.h>

int maxFreqSum(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            freq[s[i] - 'a']++;
        }
    }

    int maxVowel = 0, maxCons = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++) {
        int f = freq[vowels[i] - 'a'];
        if (f > maxVowel) {
            maxVowel = f;
        }
    }

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
        if (freq[i] > maxCons) {
            maxCons = freq[i];
        }
    }

    return maxVowel + maxCons;
}

int main() {
    char s1[] = "successes";
    char s2[] = "aeiaeia";
    
    printf("%d\n", maxFreqSum(s1)); // Output: 6
    printf("%d\n", maxFreqSum(s2)); // Output: 3
    
    return 0;
}
