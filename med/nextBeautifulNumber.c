// Next Greater Numerically Balanced Number

#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <stdbool.h>  // for bool
#include <string.h>   // for memcpy

// Helper to swap two integers
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Implement next_permutation like in C++
bool next_permutation(int *arr, int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return false;

    int j = n - 1;
    while (arr[j] <= arr[i]) j--;
    swap(&arr[i], &arr[j]);

    // reverse the tail
    int l = i + 1, r = n - 1;
    while (l < r) {
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
    return true;
}

int nextBeautifulNumber(int n) {
    const int MAX_LEN = 10;
    long long best = LLONG_MAX;

    // 2^9 = 512 subsets
    for (int mask = 1; mask < (1 << 9); ++mask) {
        int digits[20];
        int len = 0;
        bool ok = true;

        for (int d = 1; d <= 9; ++d) {
            if (mask & (1 << (d - 1))) {
                len += d;
                if (len > MAX_LEN) {
                    ok = false;
                    break;
                }
                for (int k = 0; k < d; ++k)
                    digits[len - d + k] = d;
            }
        }
        if (!ok) continue;

        // Sort digits (simple bubble sort since array small)
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (digits[i] > digits[j])
                    swap(&digits[i], &digits[j]);

        int perm[20];
        memcpy(perm, digits, len * sizeof(int));

        do {
            long long val = 0;
            for (int i = 0; i < len; i++) {
                val = val * 10 + perm[i];
                if (val > INT_MAX) break;
            }
            if (val > INT_MAX) continue;
            if (val > n && val < best)
                best = val;
        } while (next_permutation(perm, len));
    }

    return (best == LLONG_MAX) ? -1 : (int)best;
}

int main(void) {
    printf("%d\n", nextBeautifulNumber(1));    // 22
    printf("%d\n", nextBeautifulNumber(1000)); // 1333
    printf("%d\n", nextBeautifulNumber(3000)); // 3133
    return 0;
}
