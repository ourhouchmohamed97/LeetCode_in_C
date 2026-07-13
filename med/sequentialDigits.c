// Sequential Digits


int* sequentialDigits(int low, int high, int* returnSize) {
    int* ret = malloc(36 * sizeof(int));
    int count = 0;
    for (int len = 2; len <= 9; len++) {
        for (int start = 1; start <= 10 - len; start++) {
            int num = 0;
            for (int i = 0; i < len; i++) {
                num = num * 10 + (start + i);
            }
            if (num > high) {
                *returnSize = count;
                return ret;
            }
            if (num >= low) {
                ret[count++] = num;
            }
        }
    }

    *returnSize = count;
    return ret;
}