// Maximum Number of K-Divisible Components

int dfs(int node, int parent, int** adj, int* adjSize, int* values, int k, int* ans) {
    long sum = values[node];
    for(int i = 0; i < adjSize[node]; i++) {
        int nxt = adj[node][i];
        if(nxt != parent) sum += dfs(nxt, node, adj, adjSize, values, k, ans);
    }
    if(sum % k == 0) (*ans)++;
    return sum % k;
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    int* adjSize = calloc(n, sizeof(int));
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int** adj = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) adj[i] = malloc(adjSize[i] * sizeof(int));

    int* count = calloc(n, sizeof(int));
    for(int i = 0; i < edgesSize; i++) {
        int a = edges[i][0], b = edges[i][1];
        adj[a][count[a]++] = b;
        adj[b][count[b]++] = a;
    }

    int ans = 0;
    dfs(0, -1, adj, adjSize, values, k, &ans);
    return ans;
}
