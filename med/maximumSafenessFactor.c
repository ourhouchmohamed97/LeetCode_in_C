// Find the Safest Path in a Grid

typedef struct {
    int safe;
    int r;
    int c;
} Node;

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node* heap, int* size, Node node) {
    heap[++(*size)] = node;
    int i = *size;

    while (i > 1 && heap[i].safe > heap[i / 2].safe) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Node pop(Node* heap, int* size) {
    Node top = heap[1];
    heap[1] = heap[(*size)--];

    int i = 1;

    while (i * 2 <= *size) {
        int j = i * 2;

        if (j + 1 <= *size && heap[j + 1].safe > heap[j].safe)
            j++;

        if (heap[i].safe >= heap[j].safe)
            break;

        swap(&heap[i], &heap[j]);
        i = j;
    }

    return top;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return 0;

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int total = n * n;

    int** dist = malloc(n * sizeof(int*));
    int** seen = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dist[i] = malloc(n * sizeof(int));
        seen[i] = calloc(n, sizeof(int));

        for (int j = 0; j < n; j++) {
            dist[i][j] = 1000000000;
        }
    }

    int* qr = malloc(total * sizeof(int));
    int* qc = malloc(total * sizeof(int));
    int front = 0, back = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1) {
                dist[r][c] = 0;
                qr[back] = r;
                qc[back] = c;
                back++;
            }
        }
    }

    while (front < back) {
        int r = qr[front];
        int c = qc[front];
        front++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == 1000000000) {
                dist[nr][nc] = dist[r][c] + 1;
                qr[back] = nr;
                qc[back] = nc;
                back++;
            }
        }
    }

    Node* heap = malloc((total + 1) * sizeof(Node));
    int heapSize = 0;

    push(heap, &heapSize, (Node){dist[0][0], 0, 0});

    while (heapSize > 0) {
        Node cur = pop(heap, &heapSize);
        int safe = cur.safe;
        int r = cur.r;
        int c = cur.c;

        if (seen[r][c])
            continue;

        seen[r][c] = 1;

        if (r == n - 1 && c == n - 1)
            return safe;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                int newSafe = safe < dist[nr][nc] ? safe : dist[nr][nc];
                push(heap, &heapSize, (Node){newSafe, nr, nc});
            }
        }
    }

    return -1;
}