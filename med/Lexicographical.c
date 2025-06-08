#include <stdio.h>
#include <stdlib.h>

int* lexicalOrder(int n, int* returnSize) {
    int *result = malloc(sizeof(int) * n);
    *returnSize = n;

    int curr = 1;
    for (int i = 0; i < n; i++) {
        result[i] = curr;

        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            if (curr >= n) curr /= 10;
            curr++;
            while (curr % 10 == 0) curr /= 10;
        }
    }
    return result;
}

int main()
{
    int n = 34;
    int size = 0;

    int *result = lexicalOrder(n, &size);

    printf("Lexicographical array (size %d):\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}