// Find N Unique Integers Sum up to Zero

#include <stdio.h>
#include <stdlib.h>

int* sumZero(int n, int* returnSize) 
{
    *returnSize = n;
    int* arr = (int*)malloc(n * sizeof(int));
    if(!arr)
        return NULL;
    for (int i = 0; i < n; i++)
        arr[i] = 2 * i - n + 1;
    return arr;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int returnSize;
    int* result = sumZero(n, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(result);
    return 0;
}