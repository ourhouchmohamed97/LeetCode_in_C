// Convert a Number to Hexadecimal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toHex(int num) {
    if (num == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    unsigned int n = num; // This handles two's complement for negative numbers
    char hexChars[] = "0123456789abcdef";
    char buffer[9]; // Maximum 8 characters for 32 bits + null terminator
    int index = 0;

    while (n != 0) {
        int remainder = n % 16;
        buffer[index++] = hexChars[remainder];
        n /= 16;
    }

    buffer[index] = '\0';

    // Reverse the buffer to get the correct order
    for (int i = 0; i < index / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[index - 1 - i];
        buffer[index - 1 - i] = temp;
    }

    char* result = (char*)malloc((index + 1) * sizeof(char));
    strcpy(result, buffer);
    return result;
}

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);
    char* hex = toHex(num);
    printf("Hexadecimal representation: %s\n", hex);
    free(hex); // Free the allocated memory
    return 0;
}