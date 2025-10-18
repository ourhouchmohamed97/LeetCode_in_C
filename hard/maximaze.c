#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int compute_r(const int *next_pos, int n, int k, int L, int i_pos, int orig_idx, int new_idx) {
    int pos[26];
    int m = 0;
    for (int c = 0; c < 26; c++) {
        int first;
        int npL = next_pos[L * 26 + c];
        if (c == new_idx && i_pos >= L) {
            first = (i_pos < npL) ? i_pos : npL;
        } else if (c == orig_idx && i_pos >= L) {
            if (npL == i_pos) {
                int np_after = next_pos[(i_pos + 1) * 26 + c];
                first = np_after;
            } else {
                first = npL;
            }
        } else {
            first = npL;
        }
        if (first < n) {
            pos[m++] = first;
        }
    }
    if (m <= k) {
        return n - 1;
    }
    for (int i = 1; i < m; i++) {
        int key = pos[i];
        int j = i - 1;
        while (j >= 0 && pos[j] > key) {
            pos[j + 1] = pos[j];
            j--;
        }
        pos[j + 1] = key;
    }
    return pos[k] - 1;
}

int maxPartitionsAfterOperations(char* s, int k) {
    int n = (int)strlen(s);
    if (n == 0) {
        return 0;
    }
    if (k <= 0) {
        return n; 
    }

    int *next_pos = (int*)malloc((n + 1) * 26 * sizeof(int));
    if (!next_pos) return 0;
    for (int c = 0; c < 26; c++) {
        next_pos[n * 26 + c] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            next_pos[i * 26 + c] = next_pos[(i + 1) * 26 + c];
        }
        next_pos[i * 26 + (s[i] - 'a')] = i;
    }

    int *partition_start = (int*)malloc(n * sizeof(int));
    int *pref = (int*)malloc(n * sizeof(int));
    int start = 0, parts = 0;
    while (start < n) {
        int cnt[26] = {0};
        int distinct = 0;
        int j = start;
        while (j < n) {
            int idx = s[j] - 'a';
            if (cnt[idx] == 0 && distinct == k) {
                break;
            }
            if (cnt[idx] == 0) {
                distinct++;
            }
            cnt[idx]++;
            j++;
        }
        parts++;
        for (int t = start; t < j; t++) {
            partition_start[t] = start;
            pref[t] = parts;
        }
        start = j;
    }

    int *suff = (int*)malloc(n * sizeof(int));
    int end = n - 1; 
    parts = 0;
    while (end >= 0) {
        int cnt[26] = {0};
        int distinct = 0;
        int j = end;
        while (j >= 0) {
            int idx = s[j] - 'a';
            if (cnt[idx] == 0 && distinct == k) {
                break;
            }
            if (cnt[idx] == 0) {
                distinct++;
            }
            cnt[idx]++;
            j--;
        }
        parts++;
        for (int t = j + 1; t <= end; t++) {
            suff[t] = parts;
        }
        end = j;
    }

    int ans = suff[0]; 
    for (int i = 0; i < n; i++) {
        int L = partition_start[i];
        int orig = s[i] - 'a';
        int leftParts = (L > 0 ? pref[L - 1] : 0);

        for (int new_idx = 0; new_idx < 26; new_idx++) {
            if (new_idx == orig) {
                continue;
            }
            int r = compute_r(next_pos, n, k, L, i, orig, new_idx);
            if (r >= i) {
                int rightParts = (r + 1 < n ? suff[r + 1] : 0);
                int cand = 1 + leftParts + rightParts;
                if (cand > ans) ans = cand;
            } else {
                int start2 = r + 1;
                int r2 = compute_r(next_pos, n, k, start2, i, orig, new_idx);
                int rightParts = (r2 + 1 < n ? suff[r2 + 1] : 0);
                int cand = 2 + leftParts + rightParts;
                if (cand > ans) ans = cand;
            }
        }
    }

    free(next_pos);
    free(partition_start);
    free(pref);
    free(suff);
    return ans;
}