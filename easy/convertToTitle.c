// Excel Sheet Column Title

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    char* result = (char*)malloc(100 * sizeof(char));
    int index = 0;
    
    while (columnNumber > 0) {
        columnNumber--;
        int remainder = columnNumber % 26;
        result[index++] = 'A' + remainder;
        columnNumber /= 26;
    }
    result[index] = '\0';
    
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }
    
    return result;
}

int main() {
    printf("%s\n", convertToTitle(1));
    printf("%s\n", convertToTitle(28));
    printf("%s\n", convertToTitle(701));
    return 0;
}