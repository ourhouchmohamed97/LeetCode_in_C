// Minimum Cost Path with Teleportations

typedef long long ll;

typedef struct {
    int val;
    int idx;
} Cell;

static int cmpCellDesc(const void* a, const void* b) {
    const Cell* x = (const Cell*)a;
    const Cell* y = (const Cell*)b;
    if (x->val != y->val) 
        return (x->val < y->val) ? 1 : -1; 
    return (x->idx < y->idx) ? 1 : (x->idx > y->idx ? -1 : 0); \
}

static ll minll(ll a, ll b) {
    return a < b ? a : b;
}

int minCost(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    const ll INF = (ll)1e30;

    int total = m * n;

    Cell* cells = (Cell*)malloc(sizeof(Cell) * total);
    int pos = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int idx = i * n + j;
            cells[pos++] = (Cell){grid[i][j], idx};
        }
    }
    qsort(cells, total, sizeof(Cell), cmpCellDesc);

    ll* dist = (ll*)malloc(sizeof(ll) * total);
    for (int i = 0; i < total; i++) 
        dist[i] = INF;
    dist[0] = 0;

    ll best = INF;

    for (int t = 0; t <= k; t++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                ll cur = dist[idx];
                if (cur >= INF) 
                    continue;

                if (j + 1 < n) {
                    int ni = idx + 1;
                    ll cost = cur + (ll)grid[i][j + 1];
                    if (cost < dist[ni]) 
                        dist[ni] = cost;
                }
                if (i + 1 < m) {
                    int ni = idx + n;
                    ll cost = cur + (ll)grid[i + 1][j];
                    if (cost < dist[ni]) 
                        dist[ni] = cost;
                }
            }
        }
        best = minll(best, dist[total - 1]);
        if (t == k) 
            break;

        ll* nextDist = (ll*)malloc(sizeof(ll) * total);
        for (int i = 0; i < total; i++) 
            nextDist[i] = INF;

        ll move = INF;

        int p = 0;
        while (p < total) {
            int val = cells[p].val;
            int q = p;
            ll group_min = INF;
            while (q < total && cells[q].val == val) {
                ll d = dist[cells[q].idx];
                if (d < group_min) 
                    group_min = d;
                q++;
            }
            move = minll(move, group_min);
            for (int t2 = p; t2 < q; t2++) {
                int idx = cells[t2].idx;
                nextDist[idx] = move;
            }
            p = q;
        }
        free(dist);
        dist = nextDist;
    }
    free(dist);
    free(cells);
    return (best >= INF) ? -1 : (int)best;
}