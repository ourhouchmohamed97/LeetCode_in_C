// Count Submatrices With All Ones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numSubmat(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    int count = 0;
    
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            
            if (j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j-1] + 1;
            }
            
            int min_width = dp[i][j];
            for (int k = i; k >= 0; k--) {
                if (dp[k][j] == 0) break;
                min_width = (min_width < dp[k][j]) ? min_width : dp[k][j];
                count += min_width;
            }
        }
    }
    
    return count;
}

int main() {
    int mat1[3][3] = {{1,0,1},{1,1,0},{1,1,0}};
    int* mat1_ptrs[3] = {mat1[0], mat1[1], mat1[2]};
    int colSize1 = 3;
    int result1 = numSubmat(mat1_ptrs, 3, &colSize1);
    printf("Output: %d\n", result1);

    int mat2[3][4] = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    int* mat2_ptrs[3] = {mat2[0], mat2[1], mat2[2]};
    int colSize2 = 4;
    int result2 = numSubmat(mat2_ptrs, 3, &colSize2);
    printf("Output: %d\n", result2);

    return 0;
}