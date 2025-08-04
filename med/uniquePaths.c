// Unique Paths

#include <stdio.h>

int uniquePaths(int m, int n) {
    long result = 1;
    int total = m + n - 2;
    int k = m - 1;
    if (k > total - k) {
        k = total - k;
    }
    for (int i = 1; i <= k; i++) {
        result = result * (total - k + i) / i;
    }
    return (int)result;
}

int main() {
    printf("%d\n", uniquePaths(3, 7));
    printf("%d\n", uniquePaths(3, 2));
    return 0;
}