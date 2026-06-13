// Weighted Word Mapping

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    int d[26];
    for (int i = 0; i < 26; i++) {
        d[i] = weights[i];
    }
    char* ans = (char*)malloc((wordsSize + 1) * sizeof(char));
    for (int i = 0; i < wordsSize; i++) {
        int add = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            add += d[words[i][j] - 'a'];
        }
        int res = add % 26;
        ans[i] = (char)(96 + 26 - res);
    }
    ans[wordsSize] = '\0';
    return ans;
}