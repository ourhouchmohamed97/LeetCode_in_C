// Integer to Roman

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0';
    
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    
    return result;
}

int main() {
    int num1 = 3749;
    char* roman1 = intToRoman(num1);
    printf("Test case 1: %s\n", roman1);  // Expected output: "MMMDCCXLIX"
    free(roman1);
    
    int num2 = 58;
    char* roman2 = intToRoman(num2);
    printf("Test case 2: %s\n", roman2);  // Expected output: "LVIII"
    free(roman2);
    
    int num3 = 1994;
    char* roman3 = intToRoman(num3);
    printf("Test case 3: %s\n", roman3);  // Expected output: "MCMXCIV"
    free(roman3);
    
    return 0;
}