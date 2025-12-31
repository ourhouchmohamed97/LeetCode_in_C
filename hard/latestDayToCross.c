// Last Day Where You Can Still Cross

#include <stdbool.h>

int find(int* p, int x) {
    if (p[x] != x) p[x] = find(p, p[x]);
    return p[x];
}

void unite(int* p, int* r, int a, int b) {
    a = find(p, a);
    b = find(p, b);
    if (a == b) return;
    if (r[a] < r[b]) p[a] = b;
    else if (r[a] > r[b]) p[b] = a;
    else { p[b] = a; r[a]++; }
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int n = row * col;
    int top = n, bottom = n + 1;
    int* parent = malloc((n + 2) * sizeof(int));
    int* rank = calloc(n + 2, sizeof(int));
    bool* land = calloc(n, sizeof(bool));

    for (int i = 0; i < n + 2; i++) parent[i] = i;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    for (int d = cellsSize - 1; d >= 0; d--) {
        int r = cells[d][0] - 1;
        int c = cells[d][1] - 1;
        int id = r * col + c;
        land[id] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= 0 && nc >= 0 && nr < row && nc < col) {
                int nid = nr * col + nc;
                if (land[nid]) unite(parent, rank, id, nid);
            }
        }

        if (r == 0) unite(parent, rank, id, top);
        if (r == row - 1) unite(parent, rank, id, bottom);

        if (find(parent, top) == find(parent, bottom)) return d;
    }
    return 0;
}