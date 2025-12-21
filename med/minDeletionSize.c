//  Delete Columns to Make Sorted II

int minDeletionSize(char** strs, int strsSize) {
    if (strsSize <= 1){
        return 0;
    }
    int col = strlen(strs[0]);
    int sorted[strsSize - 1];
    int delete = 0;
    memset(sorted, 0, sizeof(sorted));
    for (int c = 0; c < col; c++){
        int check = 1;
        for (int r = 0; r < strsSize - 1; r++){
            if (!sorted[r] && strs[r][c] > strs[r + 1][c]){
                check = 0;
                break;
            }
        }
        if (!check){
            delete++;
            continue;
        }
        for (int r = 0; r < strsSize - 1; r++){
            if (!sorted[r] && strs[r][c] < strs[r + 1][c]){
                sorted[r] = 1;
            }
        }
    }
    return delete;
}