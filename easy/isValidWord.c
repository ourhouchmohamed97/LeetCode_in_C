// Valid Word

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* word) {
    int length = strlen(word);
    if (length < 3) {
        return false;
    }
    
    bool has_vowel = false;
    bool has_consonant = false;
    bool has_valid_chars = true;
    
    for (int i = 0; i < length; i++) {
        char c = word[i];
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                has_vowel = true;
            } else {
                has_consonant = true;
            }
        } else if (!isdigit(c)) {
            has_valid_chars = false;
        }
    }
    
    return has_valid_chars && has_vowel && has_consonant;
}

int main() {
    char* test_cases[] = {
        "234Adas",    // true - has vowel, consonant, digits, length >= 3
        "b3",         // false - length < 3
        "a3$e",       // false - contains '$'
        "Abc",        // true - has vowel and consonant
        "123",        // false - no vowels
        "Aio",       // true - all vowels but still valid (has consonants?)
        "Bcd",        // true - has consonant and vowel
        "xYz1",       // true - has vowel, consonant, digit
        "@bc",        // false - contains '@'
        "aB1#",       // false - contains '#'
        "E7h",        // true
        "O0p",       // true
        "qwr",       // false - no vowels
        "A1",         // false - length < 3
        "A$1",       // false - contains '$'
        "A1b2C3",    // true
        "aei",       // false - no consonants (all vowels)
        "BCD",       // false - no vowels
        "bCdEfG",    // false - no vowels
        "a1E",       // true
        "a1e",       // true
    };

    bool expected[] = {
        true, false, false, true, false, false, true, true, false, false,
        true, true, false, false, false, true, false, false, false, true, true
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int passed = 0;

    for (int i = 0; i < num_tests; i++) {
        bool result = isValid(test_cases[i]);
        if (result == expected[i]) {
            passed++;
        } else {
            printf("Test case failed: '%s'\n", test_cases[i]);
            printf("Expected: %s, Got: %s\n", 
                   expected[i] ? "true" : "false", 
                   result ? "true" : "false");
        }
    }

    printf("Passed %d out of %d test cases.\n", passed, num_tests);
    return 0;
}