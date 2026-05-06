/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#pragma GCC optimize("O3", "unroll-loops")
char** rotateTheBox(char** box, int r, int* boxColSize, int* returnSize,
                    int** returnColumnSizes) {
    int c = *boxColSize;
    *returnSize = c;
    *returnColumnSizes = (int*)malloc(c * sizeof(int));
    char** rotate = (char**)malloc(c * sizeof(char*));
    for (int i = 0; i < c; i++) {
        rotate[i] = (char*)malloc(r * sizeof(char));
        memset(rotate[i], '.', r);
        (*returnColumnSizes)[i] = r;
    }
    for (int i = 0; i < r; i++) {
        int bottom = c - 1;
        char* row = box[i];
        for ( int j = c - 1; j >= 0; j--) {
            if (row[j] == '#') {
                rotate[bottom][r - 1 - i] = '#';
                bottom--;
            } else if (row[j] == '*') {
                rotate[j][r - 1 - i] = '*';
                bottom = j - 1;
            }
        }
    }
    return rotate;
}