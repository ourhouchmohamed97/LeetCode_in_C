// Maximum Number of Words You Can Type

#include <stdio.h>

int canBeTypedWords(char* text, char* brokenLetters) {
    int canType = 0;
    int broken = 0;

    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            if (!broken)
                canType++;
            broken = 0;
        } else {
            for (int j = 0; brokenLetters[j]; j++) {
                if (text[i] == brokenLetters[j]) {
                    broken = 1;
                    break;
                }
            }
        }
    }
    if (!broken)
        canType++;

    return canType;
}


int main() {
    printf("%d\n", canBeTypedWords("hello world", "eo"));   // 0
    printf("%d\n", canBeTypedWords("hello world", "ad"));   // 1
    printf("%d\n", canBeTypedWords("leet code", "lt"));     // 1
    printf("%d\n", canBeTypedWords("leet code", "e"));      // 0
}
