// Count Unguarded Cells in the Grid

#include <stdio.h>
#include <stdlib.h>

#define GUARD 2
#define WALL 3
#define WATCHED 1
#define EMPTY 0

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int total = m * n;
    int* cells = (int*)calloc(total, sizeof(int));

    for (int i = 0; i < guardsSize; ++i) {
        int r = guards[i][0], c = guards[i][1];
        cells[r * n + c] = GUARD;
    }

    for (int i = 0; i < wallsSize; ++i) {
        int r = walls[i][0], c = walls[i][1];
        cells[r * n + c] = WALL;
    }

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < guardsSize; ++i) {
        int r = guards[i][0], c = guards[i][1];

        for (int d = 0; d < 4; ++d) {
            int dr = dirs[d][0], dc = dirs[d][1];
            int x = r + dr, y = c + dc;

            while (x >= 0 && x < m && y >= 0 && y < n) {
                int idx = x * n + y;
                if (cells[idx] == GUARD || cells[idx] == WALL)
                    break;
                if (cells[idx] == EMPTY)
                    cells[idx] = WATCHED;
                x += dr;
                y += dc;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < total; ++i)
        if (cells[i] == EMPTY)
            ++count;

    free(cells);
    return count;
}