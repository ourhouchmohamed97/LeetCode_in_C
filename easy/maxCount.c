//  Range Addition II

#include <stdio.h>
#include <stdlib.h>

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize == 0) {
        return m * n;
    }
    int min_a = ops[0][0];
    int min_b = ops[0][1];
    for (int i = 1; i < opsSize; i++) {
        if (ops[i][0] < min_a) {
            min_a = ops[i][0];
        }
        if (ops[i][1] < min_b) {
            min_b = ops[i][1];
        }
    }
    return min_a * min_b;
}

int main() {
    int m, n;
    printf("Enter the dimensions of the matrix (m n): ");
    scanf("%d %d", &m, &n);

    int opsSize;
    printf("Enter the number of operations: ");
    scanf("%d", &opsSize);

    int** ops = (int**)malloc(opsSize * sizeof(int*));
    for (int i = 0; i < opsSize; i++) {
        ops[i] = (int*)malloc(2 * sizeof(int));
        printf("Enter operation %d (a b): ", i + 1);
        scanf("%d %d", &ops[i][0], &ops[i][1]);
    }

    int opsColSize = 2;
    int result = maxCount(m, n, ops, opsSize, &opsColSize);
    printf("Number of maximum integers in the matrix: %d\n", result);

    for (int i = 0; i < opsSize; i++) {
        free(ops[i]);
    }
    free(ops);

    return 0;
}