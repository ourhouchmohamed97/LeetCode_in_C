// Minimum Score of a Path Between Two Cities

int find(int* root, int x) {
    if (root[x] != x) {
        root[x] = find(root, root[x]);
    }
    return root[x];
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    int* root = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        root[i] = i;
    }

    for (int i = 0; i < roadsSize; i++) {
        int x = roads[i][0];
        int y = roads[i][1];

        root[find(root, x)] = find(root, y);
    }

    int res = 1000000000;
    int g1 = find(root, 1);

    for (int i = 0; i < roadsSize; i++) {
        int x = roads[i][0];
        int d = roads[i][2];

        if (find(root, x) == g1) {
            if (d < res) {
                res = d;
            }
        }
    }

    free(root);
    return res;
}