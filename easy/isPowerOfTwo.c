// Power of Two

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

int main() {
    int test_numbers[] = {0, 1, 2, 3, 4, 5, 8, 16, 17, 32, 33, -1, -2, -4};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
    for (int i = 0; i < num_tests; i++) {
        int n = test_numbers[i];
        bool result = isPowerOfTwo(n);
        printf("%d is a power of two? %s\n", n, result ? "true" : "false");
    }
    return 0;
}
