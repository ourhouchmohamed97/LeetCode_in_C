// Get Biggest Three Rhombus Sums in a Grid

void updateTopThree(int *top, int val) {

    if (val == top[0] || val == top[1] || val == top[2])
        return;

    if (val > top[0]) {
        top[2] = top[1];
        top[1] = top[0];
        top[0] = val;
    } 
    else if (val > top[1]) {
        top[2] = top[1];
        top[1] = val;
    } 
    else if (val > top[2]) {
        top[2] = val;
    }
}

int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int top[3] = { -1, -1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            updateTopThree(top, grid[i][j]);

            int k = 1;
            while (1) {

                if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                    break;

                int total = 0;

                for (int t = 0; t < k; t++)
                    total += grid[i - k + t][j + t];

                for (int t = 0; t < k; t++)
                    total += grid[i + t][j + k - t];

                for (int t = 0; t < k; t++)
                    total += grid[i + k - t][j - t];

                for (int t = 0; t < k; t++)
                    total += grid[i - t][j - k + t];

                updateTopThree(top, total);

                k++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 3; i++)
        if (top[i] != -1)
            count++;

    *returnSize = count;

    int* result = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        result[i] = top[i];

    return result;
}