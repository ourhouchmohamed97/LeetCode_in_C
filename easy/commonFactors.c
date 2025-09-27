// Number of Common Factors

#include <stdio.h>

int commonFactors(int a, int b) {
    int count = 0;
    int limit = (a < b) ? a : b;
    for (int f = 1; f <= limit; f++) {
        if (a % f == 0 && b % f == 0)
            count++;
    }
    return count;
}

int main() {
    int a = 12, b = 6;
    printf("%d\n", commonFactors(a, b));
    return 0;
}
