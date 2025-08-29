// Alice and Bob Playing Flower Game

#include <stdio.h>

long long flowerGame(int n, int m) {
    long long even_n = n / 2;
    long long odd_n = (n + 1) / 2;
    long long even_m = m / 2;
    long long odd_m = (m + 1) / 2;
    return even_n * odd_m + odd_n * even_m;
}

int main() {
    int n, m;

    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    long long result = flowerGame(n, m);
    printf("Output: %lld\n", result);
    return 0;
}