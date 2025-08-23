// Find the Minimum Area to Cover All Ones II

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int top, bottom, left, right;
} Boundaries;

int hasOnes(int** prefix, int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    int total = prefix[r2+1][c2+1]
              - prefix[r1][c2+1]
              - prefix[r2+1][c1]
              + prefix[r1][c1];
    return total > 0;
}

Boundaries getBoundaries(int** grid, int n, int m, int** prefix, int r1, int r2, int c1, int c2) {
    Boundaries b = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};
    if (!hasOnes(prefix, r1, c1, r2, c2)) return (Boundaries){0, -1, 0, -1};
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (grid[i][j] == 1) {
                if (i < b.top) b.top = i;
                if (i > b.bottom) b.bottom = i;
                if (j < b.left) b.left = j;
                if (j > b.right) b.right = j;
            }
        }
    }
    return b;
}

int area(Boundaries b) {
    if (b.bottom < b.top || b.right < b.left) return 0;
    return (b.bottom - b.top + 1) * (b.right - b.left + 1);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minimumSum(int** grid, int n, int* gridColSize) {
    int m = gridColSize[0];
    int ans = INT_MAX;
    int** prefix = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        prefix[i] = (int*)calloc(m+1, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i+1][j+1] = grid[i][j]
                             + prefix[i][j+1]
                             + prefix[i+1][j]
                             - prefix[i][j];
        }
    }
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            Boundaries b1 = getBoundaries(grid, n, m, prefix, 0, i, 0, m-1);
            Boundaries b2 = getBoundaries(grid, n, m, prefix, i+1, j, 0, m-1);
            Boundaries b3 = getBoundaries(grid, n, m, prefix, j+1, n-1, 0, m-1);
            if (area(b1) && area(b2) && area(b3))
                ans = min(ans, area(b1) + area(b2) + area(b3));
        }
    }
    for (int i = 0; i < m-2; i++) {
        for (int j = i+1; j < m-1; j++) {
            Boundaries b1 = getBoundaries(grid, n, m, prefix, 0, n-1, 0, i);
            Boundaries b2 = getBoundaries(grid, n, m, prefix, 0, n-1, i+1, j);
            Boundaries b3 = getBoundaries(grid, n, m, prefix, 0, n-1, j+1, m-1);
            if (area(b1) && area(b2) && area(b3))
                ans = min(ans, area(b1) + area(b2) + area(b3));
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            Boundaries top = getBoundaries(grid, n, m, prefix, 0, i, 0, m-1);
            Boundaries botL = getBoundaries(grid, n, m, prefix, i+1, n-1, 0, j);
            Boundaries botR = getBoundaries(grid, n, m, prefix, i+1, n-1, j+1, m-1);
            if (area(top) && area(botL) && area(botR))
                ans = min(ans, area(top) + area(botL) + area(botR));
            Boundaries bot = getBoundaries(grid, n, m, prefix, i+1, n-1, 0, m-1);
            Boundaries topL = getBoundaries(grid, n, m, prefix, 0, i, 0, j);
            Boundaries topR = getBoundaries(grid, n, m, prefix, 0, i, j+1, m-1);
            if (area(bot) && area(topL) && area(topR))
                ans = min(ans, area(bot) + area(topL) + area(topR));
        }
    }
    for (int j = 0; j < m-1; j++) {
        for (int i = 0; i < n-1; i++) {
            Boundaries left = getBoundaries(grid, n, m, prefix, 0, n-1, 0, j);
            Boundaries rightTop = getBoundaries(grid, n, m, prefix, 0, i, j+1, m-1);
            Boundaries rightBot = getBoundaries(grid, n, m, prefix, i+1, n-1, j+1, m-1);
            if (area(left) && area(rightTop) && area(rightBot))
                ans = min(ans, area(left) + area(rightTop) + area(rightBot));
            Boundaries right = getBoundaries(grid, n, m, prefix, 0, n-1, j+1, m-1);
            Boundaries leftTop = getBoundaries(grid, n, m, prefix, 0, i, 0, j);
            Boundaries leftBot = getBoundaries(grid, n, m, prefix, i+1, n-1, 0, j);
            if (area(right) && area(leftTop) && area(leftBot))
                ans = min(ans, area(right) + area(leftTop) + area(leftBot));
        }
    }
    for (int i = 0; i <= n; i++) free(prefix[i]);
    free(prefix);
    return ans;
}

int main() {
    int grid1Data[2][3] = {{1,0,1},{1,1,1}};
    int* grid1[2];
    for (int i = 0; i < 2; i++) grid1[i] = grid1Data[i];
    int col1 = 3;
    printf("%d\n", minimumSum(grid1, 2, &col1));

    int grid2Data[2][4] = {{1,0,1,0},{0,1,0,1}};
    int* grid2[2];
    for (int i = 0; i < 2; i++) grid2[i] = grid2Data[i];
    int col2 = 4;
    printf("%d\n", minimumSum(grid2, 2, &col2));

    return 0;
}
