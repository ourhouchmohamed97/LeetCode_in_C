// XOR Operation in an Array

#include <stdio.h>

int xorOperation(int n, int start) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result ^= (start + 2 * i);
    }
    return result;
}

int main() {
    // Test case 1
    int n1 = 5, start1 = 0;
    printf("Test 1: n = %d, start = %d, XOR = %d\n", n1, start1, xorOperation(n1, start1));

    // Test case 2
    int n2 = 4, start2 = 3;
    printf("Test 2: n = %d, start = %d, XOR = %d\n", n2, start2, xorOperation(n2, start2));

    // Test case 3
    int n3 = 6, start3 = 2;
    printf("Test 3: n = %d, start = %d, XOR = %d\n", n3, start3, xorOperation(n3, start3));

    return 0;
}
