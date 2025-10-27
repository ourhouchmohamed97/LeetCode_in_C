// Number of Laser Beams in a Bank

int numberOfBeams(char **bank, int bankSize) {
    long long ans = 0;
    int prev = 0;

    for (int r = 0; r < bankSize; ++r) {
        int cur = 0;
        for (char *p = bank[r]; *p; ++p) {
            cur += (*p == '1');
        }
        if (cur > 0) {
            ans += (long long)prev * cur;
            prev = cur;
        }
    }
    return (int)ans;
}
