// Maximum Number of Balloons

int maxNumberOfBalloons(char *text) {
    int freq[26] = {0};

    for (int i = 0; text[i]; i++)
        freq[text[i] - 'a']++;

    int ans = freq['b' - 'a'];
    if (freq['a' - 'a'] < ans) ans = freq['a' - 'a'];
    if (freq['l' - 'a'] / 2 < ans) ans = freq['l' - 'a'] / 2;
    if (freq['o' - 'a'] / 2 < ans) ans = freq['o' - 'a'] / 2;
    if (freq['n' - 'a'] < ans) ans = freq['n' - 'a'];
    return ans;
}