// Maximum 69 Number

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum69Number(int num) {
    char s[10]; // Assuming the number has at most 10 digits
    sprintf(s, "%d", num);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '6') {
            s[i] = '9';
            break;
        }
    }
    return atoi(s);
}

int main() {
    int num1 = 9669;
    printf("%d\n", maximum69Number(num1)); // Output: 9969

    int num2 = 9996;
    printf("%d\n", maximum69Number(num2)); // Output: 9999

    int num3 = 9999;
    printf("%d\n", maximum69Number(num3)); // Output: 9999

    return 0;
}