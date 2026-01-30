// Minimum Cost to Convert String II

typedef long long ll;
#define INF (LLONG_MAX / 4)

typedef struct Trie {
    struct Trie *child[26];
    int id;              
} Trie;
Trie* trie_new() {
    Trie *t = (Trie*)malloc(sizeof(Trie));
    for (int i = 0; i < 26; i++) 
        t->child[i] = NULL;
    t->id = -1;
    return t;
}

int trie_add(Trie *root, const char *s, int *cnt) {
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (!root->child[c])
            root->child[c] = trie_new();
        root = root->child[c];
    }
    if (root->id == -1)
        root->id = ++(*cnt);
    return root->id;
}



long long minimumCost(char* source, char* target, char** original, int originalSize, char** changed, int changedSize, int* cost, int costSize ) {
    int n = strlen(source);

    Trie *root = trie_new();
    int id_cnt = -1;
    int maxNodes = originalSize * 2 + 5;
    ll **G = (ll**)malloc(maxNodes * sizeof(ll*));
    for (int i = 0; i < maxNodes; i++) {
        G[i] = (ll*)malloc(maxNodes * sizeof(ll));
        for (int j = 0; j < maxNodes; j++)
            G[i][j] = (i == j ? 0 : INF);
    }
    for (int i = 0; i < originalSize; i++) {
        int u = trie_add(root, original[i], &id_cnt);
        int v = trie_add(root, changed[i], &id_cnt);
        if (cost[i] < G[u][v])
            G[u][v] = cost[i];
    }

    int V = id_cnt + 1;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (G[i][k] == INF) 
                continue;
            for (int j = 0; j < V; j++) {
                if (G[k][j] == INF) 
                    continue;
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }

    ll *dp = (ll*)malloc((n + 1) * sizeof(ll));
    for (int i = 0; i <= n; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == INF) 
            continue;

        if (source[i] == target[i]) {
            if (dp[i + 1] > dp[i])
                dp[i + 1] = dp[i];
        }
        Trie *u = root, *v = root;
        for (int j = i; j < n; j++) {
            int cs = source[j] - 'a';
            int ct = target[j] - 'a';
            if (!u->child[cs] || !v->child[ct])
                break;
            u = u->child[cs];
            v = v->child[ct];
            if (u->id != -1 && v->id != -1) {
                ll w = G[u->id][v->id];
                if (w < INF && dp[j + 1] > dp[i] + w)
                    dp[j + 1] = dp[i] + w;
            }
        }
    }
    ll ans = dp[n];
    return ans >= INF ? -1 : ans;
}
