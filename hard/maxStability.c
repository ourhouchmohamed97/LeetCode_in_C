// Maximize Spanning Tree Stability with Upgrades

typedef struct {
    int u, v, w, idx;
} Edge;

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeB->w - edgeA->w;
}

int findParent(int v, int* parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

int unionSets(int a, int b, int* parent, int* size) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (size[a] < size[b]) {
            int temp = a; a = b; b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
        return 1; 
    }
    return 0;
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    int* parent = (int*)malloc(n * sizeof(int));
    int* size = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int comp = n;
    int res = INT_MAX;

    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            if (unionSets(edges[i][0], edges[i][1], parent, size)) {
                comp--;
                if (edges[i][2] < res) res = edges[i][2];
            } else {
                free(parent); free(size);
                return -1;
            }
        }
    }

    if (comp == 1) {
        free(parent); free(size);
        return res;
    }

    Edge* opt = (Edge*)malloc(edgesSize * sizeof(Edge));
    int optCount = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0) {
            opt[optCount].u = edges[i][0];
            opt[optCount].v = edges[i][1];
            opt[optCount].w = edges[i][2];
            opt[optCount].idx = i;
            optCount++;
        }
    }

    qsort(opt, optCount, sizeof(Edge), compareEdges);

    int* stab = (int*)malloc(n * sizeof(int));
    int stabCount = 0;
    for (int i = 0; i < optCount; i++) {
        if (unionSets(opt[i].u, opt[i].v, parent, size)) {
            comp--;
            stab[stabCount++] = opt[i].w;
            if (comp == 1) break;
        }
    }

    if (comp > 1) {
        free(parent); free(size); free(opt); free(stab);
        return -1;
    }


    for (int i = 1; i <= k && i <= stabCount; i++) {
        stab[stabCount - i] *= 2;
    }

    int minStab = INT_MAX;
    for (int i = 0; i < stabCount; i++) {
        if (stab[i] < minStab) minStab = stab[i];
    }

    int finalRes = (res < minStab) ? res : minStab;
    free(parent);
    free(size);
    free(opt);
    free(stab);

    return finalRes;
}