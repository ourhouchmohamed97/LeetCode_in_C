// K-th Smallest in Lexicographical Order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long countSteps(long long n, long long curr, long long next) {
    long long steps = 0;
    while (curr <= n) {
        steps += (next <= n + 1 ? next : n + 1) - curr;
        curr *= 10;
        next *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    int curr = 1;
    k--; // we already include 1 as the first element

    while (k > 0) {
        long long steps = countSteps(n, curr, curr + 1);
        if (steps <= k) {
            curr++;      // Move to next sibling
            k -= steps;  // Skip all numbers under the previous prefix
        } else {
            curr *= 10;  // Go deeper
            k--;
        }
    }

    return curr;
}

// second method -- second solution
// but there is time out problem int testcase n = 4289384 k = 1922239

int cmp(const void *a, const void *b) {
    char str1[12], str2[12];
    sprintf(str1, "%d", *(int *)a);
    sprintf(str2, "%d", *(int *)b);
    return strcmp(str1, str2);
}

int findKthNumber2(int n, int k) {
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
    qsort(arr, n, sizeof(int), cmp);
    int result = arr[k - 1];
    free(arr);
    return result;
}
int main()
{
    int n = 13;
    int k = 2;

    int result = findKthNumber(n, k);

    printf("%d-th Smallest in Lexicographical Order: %d\n", k, result);

    int res = findKthNumber2(n, k);

    printf("%d-th Smallest in Lexicographical Order: %d\n", k, res);
    return 0;
}