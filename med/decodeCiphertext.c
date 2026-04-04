// Decode the Slanted Ciphertext

#include <stdlib.h>
#include <string.h>

char* decodeCiphertext(char* encodedText, int rows) {
    if (rows == 1)
        return strdup(encodedText);

    int n = strlen(encodedText);
    int cols = n / rows;

    char* res = (char*)malloc(n + 1);
    int idx = 0;

    for (int c = 0; c < cols; c++) {
        int r = 0, j = c;
        while (r < rows && j < cols) {
            res[idx++] = encodedText[r * cols + j];
            r++;
            j++;
        }
    }

    while (idx > 0 && res[idx - 1] == ' ') {
        idx--;
    }

    res[idx] = '\0';
    return res;
}