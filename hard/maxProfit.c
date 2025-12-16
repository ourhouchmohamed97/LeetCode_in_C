// Maximum Profit from Trading Stocks with Discounts

#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef long long ll;
static const ll NEG = -(ll)1000000000000000LL;

typedef struct {
    int *a;
    int sz;
    int cap;
} IntList;

static void list_init(IntList *l) { l->a = NULL; l->sz = 0; l->cap = 0; }

static void list_push(IntList *l, int x) {
    if (l->sz == l->cap) {
        int nc = (l->cap == 0) ? 2 : (l->cap * 2);
        l->a = (int*)realloc(l->a, (size_t)nc * sizeof(int));
        l->cap = nc;
    }
    l->a[l->sz++] = x;
}

static int G_BUDGET;
static int *G_present, *G_future;
static IntList *G_tree;
static int *G_cap;

static ll **G_dp0, **G_dp1;
static int *G_dp0Len, *G_dp1Len;

static ll cap_dfs(int u) {
    ll s = (ll)G_present[u];
    for (int i = 0; i < G_tree[u].sz; i++) 
        s += cap_dfs(G_tree[u].a[i]);
    G_cap[u] = (int)((s < (ll)G_BUDGET) ? s : (ll)G_BUDGET);
    return s;
}

static ll* merge_arrays(const ll *a, int lenA, const ll *b, int lenB, int *outLen) {
    int len_a = lenA - 1;
    int len_b = lenB - 1;
    int total = len_a + len_b;
    if (total > G_BUDGET) 
        total = G_BUDGET;

    int cLen = total + 1;
    ll *c = (ll*)malloc((size_t)cLen * sizeof(ll));
    for (int i = 0; i < cLen; i++) 
        c[i] = NEG;

    int iMax = (len_a < total) ? len_a : total;
    for (int i = 0; i <= iMax; i++) {
        ll ai = a[i];
        if (ai == NEG) 
            continue;
        int maxj = (len_b < (total - i)) ? len_b : (total - i);
        for (int j = 0; j <= maxj; j++) {
            ll bj = b[j];
            if (bj == NEG) 
                continue;
            ll val = ai + bj;
            if (val > c[i + j]) 
                c[i + j] = val;
        }
    }
    *outLen = cLen;
    return c;
}

static ll* compute_u(int u, int parentBought, const ll *skip, const ll *base, int len, int *outLen) {
    int capU = len - 1;
    int price = parentBought ? (G_present[u] / 2) : G_present[u];
    ll profit = (ll)G_future[u] - (ll)price;
    ll *best = (ll*)malloc((size_t)len * sizeof(ll));
    for (int i = 0; i < len; i++) 
        best[i] = skip[i];

    if (price <= capU) {
        for (int b = price; b <= capU; b++) {
            ll left = base[b - price];
            if (left != NEG) {
                ll cand = left + profit;
                if (cand > best[b]) 
                    best[b] = cand;
            }
        }
    }

    *outLen = len;
    return best;
}

static void dfs(int u) {
    for (int i = 0; i < G_tree[u].sz; i++) 
        dfs(G_tree[u].a[i]);
    int capU = G_cap[u];
    int skipLen = capU + 1;
    int baseLen = capU + 1;
    ll *skip = (ll*)malloc((size_t)skipLen * sizeof(ll));
    ll *base = (ll*)malloc((size_t)baseLen * sizeof(ll));
    for (int i = 0; i < skipLen; i++) 
        skip[i] = NEG;
    for (int i = 0; i < baseLen; i++) 
        base[i] = NEG;
    skip[0] = 0;
    base[0] = 0;

    for (int i = 0; i < G_tree[u].sz; i++) {
        int v = G_tree[u].a[i];
        int newLen;
        ll *newSkip = merge_arrays(skip, skipLen, G_dp0[v], G_dp0Len[v], &newLen);
        free(skip);
        skip = newSkip;
        skipLen = newLen;
        ll *newBase = merge_arrays(base, baseLen, G_dp1[v], G_dp1Len[v], &newLen);
        free(base);
        base = newBase;
        baseLen = newLen;
    }
    int lenU = (skipLen < baseLen) ? skipLen : baseLen;
    G_dp0[u] = compute_u(u, 0, skip, base, lenU, &G_dp0Len[u]);
    G_dp1[u] = compute_u(u, 1, skip, base, lenU, &G_dp1Len[u]);
    free(skip);
    free(base);
}

int maxProfit(int n, int* present, int presentSize, int* future,  int futureSize, int** hierarchy, int hierarchySize, int* hierarchyColSize, int budget) {
    (void)presentSize; (void)futureSize; (void)hierarchyColSize;

    G_BUDGET = budget;
    G_present = present;
    G_future  = future;

    G_tree = (IntList*)malloc((size_t)n * sizeof(IntList));
    int *inDeg = (int*)calloc((size_t)n, sizeof(int));
    for (int i = 0; i < n; i++) list_init(&G_tree[i]);

    for (int i = 0; i < hierarchySize; i++) {
        int u = hierarchy[i][0] - 1;
        int v = hierarchy[i][1] - 1;
        list_push(&G_tree[u], v);
        inDeg[v]++;
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        if (inDeg[i] == 0) { 
            root = i; 
            break; 
        }
    }
    G_cap = (int*)calloc((size_t)n, sizeof(int));
    cap_dfs(root);
    G_dp0 = (ll**)calloc((size_t)n, sizeof(ll*));
    G_dp1 = (ll**)calloc((size_t)n, sizeof(ll*));
    G_dp0Len = (int*)calloc((size_t)n, sizeof(int));
    G_dp1Len = (int*)calloc((size_t)n, sizeof(int));
    dfs(root);

    ll ans = NEG;
    for (int i = 0; i < G_dp0Len[root]; i++) {
        if (G_dp0[root][i] > ans) 
            ans = G_dp0[root][i];
    }
    for (int i = 0; i < n; i++) {
        free(G_tree[i].a);
        free(G_dp0[i]);
        free(G_dp1[i]);
    }
    free(G_tree);
    free(inDeg);
    free(G_cap);
    free(G_dp0);
    free(G_dp1);
    free(G_dp0Len);
    free(G_dp1Len);
    return (int)ans;
}