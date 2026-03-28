// Find the String with LCP

char* findTheString(int** lcp, int lcpSize, int* lcpColSize) {
    int n = lcpSize;
    char* word = (char*)malloc((n + 1) * sizeof(char));
    memset(word, 0, sizeof(char) * (n + 1));
    char current = 'a';

    for (int i = 0; i < n; i++) {
        if (word[i] == '\0') {
            if (current > 'z') {
                word[0] = '\0';
                return word;
            }
            word[i] = current;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = word[i];
                }
            }
            current++;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (word[i] != word[j]) {
                if (lcp[i][j] != 0) {
                    word[0] = '\0';
                    return word;
                }
            } else {
                if (i == n - 1 || j == n - 1) {
                    if (lcp[i][j] != 1) {
                        word[0] = '\0';
                        return word;
                    }
                } else {
                    if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        word[0] = '\0';
                        return word;
                    }
                }
            }
        }
    }

    return word;
}