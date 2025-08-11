// Range Product Queries of Powers

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int powers[32];
    int size = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1U << i)) {
            powers[size++] = 1 << i;
        }
    }
    
    long long* prefix = (long long*)malloc((size + 1) * sizeof(long long));
    prefix[0] = 1;
    for (int i = 1; i <= size; i++) {
        prefix[i] = (prefix[i-1] * powers[i-1]) % MOD;
    }
    
    int* answers = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        long long product = 1;
        for (int j = left; j <= right; j++) {
            product = (product * powers[j]) % MOD;
        }
        answers[i] = (int)product;
    }
    
    free(prefix);
    *returnSize = queriesSize;
    return answers;
}

int main() {
    int n = 15;
    int queries[][2] = {{0, 1}, {2, 2}, {0, 3}};
    int queriesSize = 3;
    int queriesColSize[] = {2, 2, 2};
    int returnSize;
    
    int** queriesPtr = (int**)malloc(queriesSize * sizeof(int*));
    for (int i = 0; i < queriesSize; i++) {
        queriesPtr[i] = (int*)malloc(2 * sizeof(int));
        queriesPtr[i][0] = queries[i][0];
        queriesPtr[i][1] = queries[i][1];
    }
    
    int* answers = productQueries(n, queriesPtr, queriesSize, queriesColSize, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d\n", answers[i]);
    }
    
    for (int i = 0; i < queriesSize; i++) {
        free(queriesPtr[i]);
    }
    free(queriesPtr);
    free(answers);
    
    return 0;
}