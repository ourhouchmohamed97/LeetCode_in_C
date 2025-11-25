// Smallest Integer Divisible by K

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int smallestRepunitDivByK(int k) {
    int rem = 0;
    for (int length = 1; length <= k; ++length) {
        rem = (rem * 10 + 1) % k;
        if (rem == 0)
            return length;
    }
    return -1;
}

int main()
{
    printf("%d\n", smallestRepunitDivByK(1));
    printf("%d\n", smallestRepunitDivByK(2));
    printf("%d\n", smallestRepunitDivByK(3));
}
