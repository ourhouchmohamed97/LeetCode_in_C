//  Zigzag Conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    
    int len = strlen(s);
    char** rows = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(len + 1);
        rows[i][0] = '\0';
    }
    
    int currentRow = 0;
    int goingDown = 0;
    
    for (int i = 0; i < len; i++) {
        strncat(rows[currentRow], &s[i], 1);
        
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }
    
    char* result = (char*)malloc(len + 1);
    result[0] = '\0';
    
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);
    
    return result;
}

int main() {
    char s1[] = "PAYPALISHIRING";
    printf("%s\n", convert(s1, 3)); // Output: "PAHNAPLSIIGYIR"
    
    char s2[] = "PAYPALISHIRING";
    printf("%s\n", convert(s2, 4)); // Output: "PINALSIGYAHRPI"
    
    char s3[] = "A";
    printf("%s\n", convert(s3, 1)); // Output: "A"
    
    return 0;
}