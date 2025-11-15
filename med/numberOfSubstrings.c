// Count the Number of Substrings With Dominant Ones

int numberOfSubstrings(char *s) {
    int n = 0;
    while (s[n]) {
        n++;
    }

    int *c1 = (int*)malloc((n + 2) * sizeof(int));
    int c1_size = 1;
    c1[0] = 0;

    int counts[2] = {0, 0};
    int res = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        counts[c - '0']++;

        if (c == '0') {
            c1[c1_size++] = counts[1];
        }

        res += counts[1] - c1[counts[0]];

        for (int c0 = counts[0] - 1; c0 >= 0; c0--) {
            int num0 = counts[0] - c0;
            if (num0 * num0 > counts[1]) {
                break;
            }

            int hi = counts[1] - c1[c0];
            int lo = counts[1] - c1[c0 + 1];

            if (hi < num0 * num0) {
                continue;
            }
            res += fmax(0, hi - fmax(lo, num0 * num0) + 1);
        }
    }

    free(c1);
    return res;
}