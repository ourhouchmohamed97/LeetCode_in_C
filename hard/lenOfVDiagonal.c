// Length of Longest V-Shaped Diagonal Segment

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma GCC optimize("O3, unroll-loops")
static int d[5] = {1, 1, -1, -1, 1}; // (1,1),(1,-1),(-1,-1),(-1,1)
static bool isOutSide(int i, int j, int n, int m) { 
    return i<0 || i>=n || j<0 || j>=m; 
}
static int lenOfVDiagonal(int** grid, int n, int* gridColSize) {
    const int m=*gridColSize;
    int dp[n][m][4];// gcc supports the arrays with variable len
    memset(dp, 0, sizeof(dp));
    // step (1,1)
    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--)
            if ((grid[i+1][j+1]^2)==grid[i][j])
                dp[i][j][0]=1+dp[i+1][j+1][0];
    // step (1,-1)
        for(int j=1; j<m; j++)
            if ((grid[i+1][j-1]^2)==grid[i][j])
                dp[i][j][1]=1+dp[i+1][j-1][1];
    }
    // step (-1,-1)
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++)
            if ((grid[i-1][j-1]^2)==grid[i][j])
                dp[i][j][2]=1+dp[i-1][j-1][2];
    // step (-1,1)
        for(int j=m-2; j>=0; j--)
            if ((grid[i-1][j+1]^2)==grid[i][j])
                dp[i][j][3]=1+dp[i-1][j+1][3];
    }

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]==1) {
                ans=fmax(ans, 1);
                for (int dir=0; dir<4; dir++) {
                    int s=i+d[dir], t=j+d[dir+1];
                    if (isOutSide(s, t, n, m) || grid[s][t]!=2) continue;
                    const int newDir=(dir+1)&3;// same as %4
                        
                    for(int cnt=1; 
                    !isOutSide(s, t, n, m)&&grid[s][t]==((cnt&1)<<1);
                    cnt++, s+=d[dir], t+=d[dir+1]) {
                        ans=fmax(ans, cnt+dp[s][t][newDir]+1);  
                    }
                }
            }
        }
    }
    return ans;  
}

int main() {
    // Example grid
    int gridData[5][5] = {
        {2,2,1,2,2},
        {2,0,2,2,0},
        {2,0,1,1,0},
        {1,0,2,2,2},
        {2,0,0,2,2}
    };
    int n = 5;
    int m = 5;
    int* grid[5];
    for (int i = 0; i < 5; i++) {
        grid[i] = gridData[i];
    }
    int gridColSize = 5;
    int result = lenOfVDiagonal(grid, n, &gridColSize);
    printf("Result: %d\n", result); // Expected: 5
    return 0;
}