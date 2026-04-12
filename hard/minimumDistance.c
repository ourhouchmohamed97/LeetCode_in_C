// Minimum Distance to Type a Word Using Two Fingers

#define INF 1e9
int dist(int a, int b) {
    if (a == 26 || b == 26) 
        return 0;
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
}

int minimumDistance(char * word) {
    int n = strlen(word);
    int dp[27], next_dp[27];
    for (int i = 0; i < 27; i++) 
        dp[i] = INF;
    dp[26] = 0;
    int prev = word[0] - 'A';

    for (int i = 1; i < n; i++) {
        int cur = word[i] - 'A';
        for (int j = 0; j < 27; j++) 
            next_dp[j] = INF;
        for (int free = 0; free < 27; free++) {
            if (dp[free] == INF) 
                continue;
            int d1 = dp[free] + dist(prev, cur);
            if (d1 < next_dp[free]) 
                next_dp[free] = d1;
            int d2 = dp[free] + dist(free, cur);
            if (d2 < next_dp[prev]) 
                next_dp[prev] = d2;
        }
        for (int j = 0; j < 27; j++) 
            dp[j] = next_dp[j];
        prev = cur;
    }

    int res = INF;
    for (int i = 0; i < 27; i++) 
        if (dp[i] < res) 
            res = dp[i];
    return res;
}