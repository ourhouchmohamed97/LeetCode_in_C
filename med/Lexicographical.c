#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// second method -- second solution

int cmp(const void *a, const void *b) {
    char str1[12], str2[12];
    sprintf(str1, "%d", *(int *)a);
    sprintf(str2, "%d", *(int *)b);
    return strcmp(str1, str2);
}

int* lexicalOrder2(int n, int* returnSize) {
    int *arr = malloc(sizeof(int) * n);
    *returnSize = n;

    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
    qsort(arr, n, sizeof(int), cmp);
    return arr;
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
    result = lexicalOrder2(n, &size);

    printf("second method Lexicographical array (size %d):\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    printf("\n");
    free(result);
    return 0;
}