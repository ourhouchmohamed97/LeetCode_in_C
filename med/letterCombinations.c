// Letter Combinations of a Phone Number

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping of digits to letters
const char* letters[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

int numCombinations(char* digits) {
    if (digits[0] == '\0') return 0;
    int count = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        int digit = digits[i] - '0';
        count *= strlen(letters[digit]);
    }
    return count;
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') {
        return NULL;
    }
    
    int total = numCombinations(digits);
    char** result = (char**)malloc(total * sizeof(char*));
    
    result[0] = (char*)malloc(1);
    result[0][0] = '\0';
    *returnSize = 1;
    
    for (int i = 0; digits[i] != '\0'; i++) {
        int digit = digits[i] - '0';
        const char* currentLetters = letters[digit];
        int currentSize = *returnSize;
        int newSize = currentSize * strlen(currentLetters);
        
        char** temp = (char**)malloc(newSize * sizeof(char*));
        int index = 0;
        
        for (int j = 0; j < currentSize; j++) {
            for (int k = 0; k < strlen(currentLetters); k++) {
                temp[index] = (char*)malloc(strlen(result[j]) + 2);
                strcpy(temp[index], result[j]);
                temp[index][strlen(result[j])] = currentLetters[k];
                temp[index][strlen(result[j]) + 1] = '\0';
                index++;
            }
            free(result[j]);
        }
        
        free(result);
        result = temp;
        *returnSize = newSize;
    }
    
    return result;
}

int main() {
    char* digits = "23";
    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);
    
    printf("Combinations for \"%s\":\n", digits);
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\" ", combinations[i]);
        free(combinations[i]);
    }
    printf("\n");
    free(combinations);
    
    return 0;
}