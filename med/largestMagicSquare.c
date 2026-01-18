// Largest Magic Square

#include <stdio.h>
#include <stdbool.h>

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int max_k = 0;
    
    // Precompute the prefix sums for rows and columns
    int rowPrefix[m + 1][n + 1];
    int colPrefix[m + 1][n + 1];
    
    // Initialize rowPrefix and colPrefix
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                rowPrefix[i][j] = 0;
                colPrefix[i][j] = 0;
            } else {
                rowPrefix[i][j] = rowPrefix[i][j - 1] + grid[i - 1][j - 1];
                colPrefix[i][j] = colPrefix[i - 1][j] + grid[i - 1][j - 1];
            }
        }
    }
    
    // Iterate over all possible top-left corners (i,j)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // The maximum possible k starting at (i,j)
            int max_possible = (m - i) < (n - j) ? (m - i) : (n - j);
            for (int k = max_possible; k > 0; k--) {
                if (k <= max_k) {
                    break; // No need to check smaller k if we already have a larger max_k
                }
                // Check if the k x k square starting at (i,j) is a magic square
                bool isMagic = true;
                int targetSum = rowPrefix[i + 1][j + k] - rowPrefix[i + 1][j];
                
                // Check all rows
                for (int row = 0; row < k; row++) {
                    int currentRowSum = rowPrefix[i + row + 1][j + k] - rowPrefix[i + row + 1][j];
                    if (currentRowSum != targetSum) {
                        isMagic = false;
                        break;
                    }
                }
                if (!isMagic) continue;
                
                // Check all columns
                for (int col = 0; col < k; col++) {
                    int currentColSum = colPrefix[i + k][j + col + 1] - colPrefix[i][j + col + 1];
                    if (currentColSum != targetSum) {
                        isMagic = false;
                        break;
                    }
                }
                if (!isMagic) continue;
                
                // Check main diagonal
                int diag1 = 0;
                for (int d = 0; d < k; d++) {
                    diag1 += grid[i + d][j + d];
                }
                if (diag1 != targetSum) {
                    isMagic = false;
                    continue;
                }
                
                // Check anti-diagonal
                int diag2 = 0;
                for (int d = 0; d < k; d++) {
                    diag2 += grid[i + d][j + k - 1 - d];
                }
                if (diag2 != targetSum) {
                    isMagic = false;
                    continue;
                }
                
                if (isMagic && k > max_k) {
                    max_k = k;
                }
            }
        }
    }
    
    return max_k;
}