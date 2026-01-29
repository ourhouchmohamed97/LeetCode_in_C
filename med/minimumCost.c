// Minimum Cost to Convert String I

#define INF 1000000000000000000LL
#define MAX 26
#define MAXE 2000

typedef struct {
    int v, w;
} Edge;

Edge graph[MAX][MAXE];
int deg[MAX];

void dijkstra(int start, long long dist[]) {
    int used[MAX] = {0};
    for (int i = 0; i < MAX; i++)
        dist[i] = INF;
    dist[start] = 0;

    for (int it = 0; it < MAX; it++) {
        int u = -1;
        for (int i = 0; i < MAX; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        if (u == -1 || dist[u] == INF) 
            break;
        used[u] = 1;

        for (int i = 0; i < deg[u]; i++) {
            int v = graph[u][i].v;
            int w = graph[u][i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}
long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    memset(deg, 0, sizeof(deg));

    for (int i = 0; i < costSize; i++) {
        int u = original[i] - 'a';
        graph[u][deg[u]++] = (Edge){
            changed[i] - 'a', cost[i]
        };
    }

    long long compute[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        dijkstra(i, compute[i]);
    }

    long long total = 0;
    for (int i = 0; source[i]; i++) {
        int s = source[i] - 'a';
        int t = target[i] - 'a';
        if (compute[s][t] >= INF)
            return -1;
        total += compute[s][t];
    }
    return total;
}
