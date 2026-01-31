// Find Smallest Letter Greater Than Target

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    char res = letters[0];
    int flag = 0;

    for (int i = 0; i < lettersSize; i++) {
        char ch = letters[i];
        if (!flag) {
            if (ch > target) {
                res = ch;
                flag = 1;
            }
        } else {
            if (ch > target && ch < res) res = ch;
        }
    }

    return res;
}