// Find the K-Beauty of a Number

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int divisorSubstrings(int num, int k) {
    char s[20];
    sprintf(s, "%d", num);
    int n = strlen(s);
    int count = 0;

    for (int i = 0; i <= n - k; i++) {
        char sub[20];
        strncpy(sub, s + i, k);
        sub[k] = '\0';

        int val = atoi(sub);
        if (val != 0 && num % val == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int num1 = 240, k1 = 2;
    int num2 = 430043, k2 = 2;

    printf("%d\n", divisorSubstrings(num1, k1)); // Output: 2
    printf("%d\n", divisorSubstrings(num2, k2)); // Output: 2

    return 0;
}
