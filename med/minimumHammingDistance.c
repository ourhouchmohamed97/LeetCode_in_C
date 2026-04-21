// Minimize Hamming Distance After Swap Operations

int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void uni(int* parent, int* rank, int i, int j) {
    int root_i = find(parent, i);
    int root_j = find(parent, j);
    if (root_i != root_j) {
        if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        } else if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        } else {
            parent[root_i] = root_j;
            rank[root_j]++;
        }
    }
}

typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

void update_freq(Node** hashTable, int size, int val, int delta) {
    int h = abs(val) % size;
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->key == val) {
            curr->count += delta;
            return;
        }
        curr = curr->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = val;
    newNode->count = delta;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int get_freq(Node** hashTable, int size, int val) {
    int h = abs(val) % size;
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->key == val) 
            return curr->count;
        curr = curr->next;
    }
    return 0;
}

int minimumHammingDistance(int* source, int sourceSize, int* target, int targetSize, int** allowedSwaps, int allowedSwapsSize, int* allowedSwapsColSize) {
    int n = sourceSize;
    int* parent = (int*)malloc(n * sizeof(int));
    int* rank = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < allowedSwapsSize; i++) {
        uni(parent, rank, allowedSwaps[i][0], allowedSwaps[i][1]);
    }

    int** groups = (int**)calloc(n, sizeof(int*));
    int* groupSizes = (int*)calloc(n, sizeof(int));
    int* groupCaps = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int root = find(parent, i);
        if (groupSizes[root] == groupCaps[root]) {
            groupCaps[root] = groupCaps[root] == 0 ? 2 : groupCaps[root] * 2;
            groups[root] = (int*)realloc(groups[root], groupCaps[root] * sizeof(int));
        }
        groups[root][groupSizes[root]++] = i;
    }

    int totalHamming = 0;

    for (int i = 0; i < n; i++) {
        if (groupSizes[i] == 0) 
            continue;

        int m = groupSizes[i];
        int hashSize = m < 7 ? 7 : m; 
        Node** hashTable = (Node**)calloc(hashSize, sizeof(Node*));

        for (int j = 0; j < m; j++) {
            update_freq(hashTable, hashSize, source[groups[i][j]], 1);
        }

        for (int j = 0; j < m; j++) {
            int targetVal = target[groups[i][j]];
            int count = get_freq(hashTable, hashSize, targetVal);
            if (count > 0) {
                update_freq(hashTable, hashSize, targetVal, -1);
            } else {
                totalHamming++;
            }
        }

        for (int j = 0; j < hashSize; j++) {
            Node* curr = hashTable[j];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                free(temp);
            }
        }
        free(hashTable);
        free(groups[i]);
    }

    free(parent);
    free(rank);
    free(groups);
    free(groupSizes);
    free(groupCaps);

    return totalHamming;
}