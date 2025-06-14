// Reverse Integer

#include <stdio.h>
#include <limits.h>

int reverse(int x){
    int reversed = 0;
    int s = 1;
    if(x < 0 && x != -2147483648) {
        s = -1;
        x = -x;
    }
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
            return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
            return 0;
        
        reversed = reversed * 10 + digit;
    }
    return reversed * s;
}

int main() {
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    
    int result = reverse(x);
    if (result == 0) {
        printf("Overflow occurred.\n");
    } else {
        printf("Reversed integer: %d\n", result);
    }
    
    return 0;
}