// Three Divisors

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isThree(int n) {
    int root = (int)sqrt(n);
    if (root * root != n) return false;
    return isPrime(root);
}

int main() {
    int n;
    scanf("%d", &n);
    if (isThree(n)) printf("true\n");
    else printf("false\n");
    return 0;
}
