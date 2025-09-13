// Count of Matches in Tournament

#include <stdio.h>

int numberOfMatches(int n) {
    return (n - 1);
}

int main(void) {
    int n1 = 7;
    int n2 = 14;

    printf("n = %d -> %d\n", n1, numberOfMatches(n1));
    printf("n = %d -> %d\n", n2, numberOfMatches(n2));

    return 0;
}