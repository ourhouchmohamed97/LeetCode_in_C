// Number of Ways to Assign Edge Weights I

#include <stdlib.h>
#define MOD 1000000007
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void addEdge(Node** graph, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = graph[u];
    graph[u] = node;
}

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;

}

int dfs(int node, int prev, Node** graph) {
    int dist = 0;
    for (Node* cur = graph[node]; cur != NULL; cur = cur->next) {
        int c = cur->val;
        if (c != prev) {
            int childDist = dfs(c, node, graph) + 1;
            if (childDist > dist) 
                dist = childDist;
        }
    }
    return dist;
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    Node** graph = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    int d = dfs(1, 0, graph);
    return (int)modPow(2, d - 1);

}