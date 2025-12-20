// Delete Columns to Make Sorted

#pragma GCC optimize("O3, unroll-loops")
int minDeletionSize(char** strs, int n) {
    int cnt=0;
    for(int j=0; strs[0][j]!='\0'; j++){
        for (int i=0; i<n-1; i++){
            if(strs[i][j]>strs[i+1][j]){
                cnt++;
                 break;
            }
        }
    }
    return cnt;
}