// Count Negative Numbers in a Sorted Matrix

int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    int row = 0;
    int col = n - 1;
    int count = 0;
    
    while (row < m && col >= 0) {
        if (grid[row][col] < 0) {
            // All elements below this are negative
            count += (m - row);
            col--;
        } else {
            row++;
        }
    }
    
    return count;
}