// Process String with Special Operations II

#include <string.h>

#define N 100000
static long long Len[N];

char processStr(char* s, long long k) {
    const int n = (int)strlen(s);
    long long L = 0;
    for (int i = 0; i < n; i++) {
        const char c = s[i];
        switch (c) {
            case '*': L -= (L > 0); break;
            case '#': L <<= 1; break;
            case '%': break;
            default: L++;
        }
        Len[i] = L;
    }
    if (L - 1 < k) return '.';
    for (int i = n - 1; i >= 0; i--) {
        const char c = s[i];
        L = Len[i];
        if (L == 0) continue;
        switch (c) {
            case '*': break;
            case '#':
                if (k >= L / 2) k -= L / 2;
                break;
            case '%':
                k = L - 1 - k;
                break;
            default:
                if (k == L - 1) return c;
        }
    }
    return '.';
}
