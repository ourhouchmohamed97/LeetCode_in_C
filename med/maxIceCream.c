// Maximum Ice Cream Bars

#pragma GCC optimize("O3, unroll-loops")
static int freq[100001] = {0};
static int maxIceCream(int* costs, int n, int coins) {
    int xMax = 0;
    for (int i = 0; i < n; i++) {
        const int x = costs[i];
        freq[x]++;
        xMax += (-(x > xMax) & x - xMax);
    }
    int cnt = 0;
    for (int x = 1; x <= xMax && coins > 0; x++) {
        const int f = freq[x];
        if (f == 0)
            continue;
        int q = coins / x;
        int buy = fmin(q, f);
        cnt += buy;
        coins -= buy * x;
    }
    for (int i = 0; i < n; i++)
        freq[costs[i]] = 0;
    return cnt;
}