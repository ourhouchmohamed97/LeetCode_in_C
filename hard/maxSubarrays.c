// Maximize Subarrays After Removing One Conflicting Pair

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

long long maxSubarrays(int n, int** cp, int cp_size, int* cp_col_size) {
    int* s = (int*)calloc(n + 1, sizeof(int));
    int* s2 = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < cp_size; ++i) {
        int a = cp[i][0], b = cp[i][1];
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (s[b] < a) {
            s2[b] = s[b];
            s[b] = a;
        } else if (s2[b] < a) {
            s2[b] = a;
        }
    }
    
    int m1 = 0, m2 = 0;
    long long ans = 0, delta = 0, md = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (s[i] > 0) {
            if (s[i] > m1) {
                m2 = max(m1, s2[i]);
                m1 = s[i];
                md = max(md, delta);
                delta = 0;
            } else if (s[i] > m2) {
                m2 = s[i];
            }
        }
        ans += (i - m1);
        delta += (m1 - m2);
    }

    free(s);
    free(s2);

    return ans + max(md, delta);
}

int main() {
    int n = 4;
    int* cp[] = {(int[]){2, 3}, (int[]){1, 4}};
    int cp_size = 2;
    int cp_col_size[] = {2, 2};
    
    long long result = maxSubarrays(n, cp, cp_size, cp_col_size);
    printf("Maximum number of subarrays: %lld\n", result);
    
    return 0;
}