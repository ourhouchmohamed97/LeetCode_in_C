// Check if There is a Valid Path in a Grid

#include <stdbool.h>

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    bool dirs[7][4] = {
        {false, false, false, false}, 
        {true,  true,  false, false}, 
        {false, false, true,  true }, 
        {true,  false, false, true }, 
        {false, true,  false, true }, 
        {true,  false, true,  false}, 
        {false, true,  true,  false}  
    };

    int moves[4][4] = {
        {0, -1, 0, 1}, 
        {0, 1, 1, 0},  
        {-1, 0, 2, 3}, 
        {1, 0, 3, 2}   
    };

    bool** visited = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)calloc(cols, sizeof(bool));
    }

    int* queueR = (int*)malloc(rows * cols * sizeof(int));
    int* queueC = (int*)malloc(rows * cols * sizeof(int));
    int head = 0, tail = 0;

    queueR[tail] = 0;
    queueC[tail] = 0;
    tail++;
    visited[0][0] = true;

    while (head < tail) {
        int r = queueR[head];
        int c = queueC[head];
        head++;

        if (r == rows - 1 && c == cols - 1) {
            for (int i = 0; i < rows; i++) 
                free(visited[i]);
            free(visited); 
            free(queueR); 
            free(queueC);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + moves[i][0];
            int nc = c + moves[i][1];
            int outDir = moves[i][2];
            int inDir = moves[i][3];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                int currPipe = grid[r][c];
                int nextPipe = grid[nr][nc];
                if (dirs[currPipe][outDir] && dirs[nextPipe][inDir]) {
                    visited[nr][nc] = true;
                    queueR[tail] = nr;
                    queueC[tail] = nc;
                    tail++;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) 
        free(visited[i]);
    free(visited); 
    free(queueR); 
    free(queueC);
    
    return false;
}