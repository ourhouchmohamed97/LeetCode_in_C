// Concatenate Non-Zero Digits and Multiply by Sum II

#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX 100001

static int pow_table[MAX];
static int initialized = 0;

static void init_pow_table() {
    if (initialized) return;
    initialized = 1;
    pow_table[0] = 1;
    for (int i = 1; i < MAX; i++) {
        pow_table[i] = (long long)pow_table[i - 1] * 10 % MOD;
    }
}

int* sumAndMultiply(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    init_pow_table();
    
    int n = strlen(s);
    
    int* A = (int*)calloc(n + 1, sizeof(int));
    int* B = (int*)calloc(n + 1, sizeof(int));
    int* len = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';            
        A[i + 1] = A[i] + d;
        
        if (d) {
            B[i + 1] = ((long long)B[i] * 10 + d) % MOD;
            len[i + 1] = len[i] + 1;
        } else {
            B[i + 1] = B[i];
            len[i + 1] = len[i];
        }
    }

    int* res = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1] + 1;

        long long sub = (long long)B[l] * pow_table[len[r] - len[l]] % MOD;
        long long x = (B[r] - sub + MOD) % MOD;

        res[i] = (int)(x * (A[r] - A[l]) % MOD);
    }

    free(A);
    free(B);
    free(len);

    return res;
}
