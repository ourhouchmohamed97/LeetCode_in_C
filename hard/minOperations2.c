// Minimum Operations to Equalize Binary String

#include <string.h>

static long long ceil_div(long long x, long long y) {
    return (x + y - 1) / y;
}

int minOperations(char* s, int k) {
    int n = (int)strlen(s);
    if (k <= 0)
        return -1;

    long long zero = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zero++;

    if (n == k) {
        if (zero == 0)
            return 0;
        else if (zero == n)
            return 1;
        else
            return -1;
    }

    long long INF = (1LL << 60);
    long long res = INF;

    if (zero % 2 == 0) {
        long long m1 = ceil_div(zero, k);
        long long m2 = ceil_div(zero, n - k);
        long long m = (m1 > m2) ? m1 : m2;
        if (m % 2 == 1)
            m++;
        if (m < res)
            res = m;
    }

    if (zero % 2 == (k % 2)) {
        long long m1 = ceil_div(zero, k);
        long long m2 = ceil_div((long long)n - zero, n - k);
        long long m = (m1 > m2) ? m1 : m2;
        if (m % 2 == 0)
            m++;
        if (m < res)
            res = m;
    }

    return (res < INF) ? (int)res : -1;
}