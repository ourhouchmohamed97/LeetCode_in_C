int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int n = wordsSize;
    int res = n;

    for (int i = 0; i < n; i++) {
        if (strcmp(words[i], target) == 0) {
            int distance = abs(i - startIndex);
            int best = distance < (n - distance) ? distance : (n - distance);
            if (best < res) {
                res = best;
            }
        }
    }

    return res == n ? -1 : res;
}