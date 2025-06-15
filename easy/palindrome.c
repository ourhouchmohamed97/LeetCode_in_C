// Palindrome Number

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int numLength(int num) {
    if (num == 0) return 1;
    return (int)log10(abs(num)) + 1;
}

bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x == 0) return true;

    int len = numLength(x);
    char *str = (char *)malloc(len + 1);
    if(!str) return false;
    int i = 0;
    while(x > 0)
    {
        int digit = x % 10;
        str[i++] = '0' + digit;
        x /= 10;
    }
    str[i] = '\0';
    for (int j = 0; j < len / 2; j++) {
        if (str[j] != str[len - j - 1])
            return false;
    }
    free(str);
    return true;
}

int main() {
    int num = -121;
    if (isPalindrome(num)) {
        printf("%d is a palindrome\n", num);
    } else {
        printf("%d is not a palindrome\n", num);
    }
    return 0;
}