// Trapping Rain Water II

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int height;
    int x, y;
} Cell;

typedef struct {
    Cell *arr;
    int size, capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (Cell*)malloc(sizeof(Cell) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void push(MinHeap *h, Cell c) {
    int i = h->size++;
    h->arr[i] = c;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p].height <= h->arr[i].height) break;
        Cell tmp = h->arr[p];
        h->arr[p] = h->arr[i];
        h->arr[i] = tmp;
        i = p;
    }
}

Cell pop(MinHeap *h) {
    Cell root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if (l < h->size && h->arr[l].height < h->arr[smallest].height) smallest = l;
        if (r < h->size && h->arr[r].height < h->arr[smallest].height) smallest = r;
        if (smallest == i) break;
        Cell tmp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = tmp;
        i = smallest;
    }
    return root;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    if (heightMapSize <= 2 || *heightMapColSize <= 2) return 0;
    int m = heightMapSize, n = *heightMapColSize;
    bool **visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) visited[i] = (bool*)calloc(n, sizeof(bool));
    MinHeap *heap = createHeap(m * n);
    for (int i = 0; i < m; i++) {
        push(heap, (Cell){heightMap[i][0], i, 0}); visited[i][0] = true;
        push(heap, (Cell){heightMap[i][n-1], i, n-1}); visited[i][n-1] = true;
    }
    for (int j = 1; j < n-1; j++) {
        push(heap, (Cell){heightMap[0][j], 0, j}); visited[0][j] = true;
        push(heap, (Cell){heightMap[m-1][j], m-1, j}); visited[m-1][j] = true;
    }
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int water = 0;
    while (heap->size > 0) {
        Cell c = pop(heap);
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dirs[d][0], ny = c.y + dirs[d][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (heightMap[nx][ny] < c.height) water += c.height - heightMap[nx][ny];
            push(heap, (Cell){ heightMap[nx][ny] > c.height ? heightMap[nx][ny] : c.height, nx, ny });
        }
    }
    return water;
}

int main() {
    int arr1[3][6] = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    int* h1[3]; for (int i = 0; i < 3; i++) h1[i] = arr1[i];
    int n1 = 6;
    printf("%d\n", trapRainWater(h1, 3, &n1));

    int arr2[5][5] = {
        {3,3,3,3,3},
        {3,2,2,2,3},
        {3,2,1,2,3},
        {3,2,2,2,3},
        {3,3,3,3,3}
    };
    int* h2[5]; for (int i = 0; i < 5; i++) h2[i] = arr2[i];
    int n2 = 5;
    printf("%d\n", trapRainWater(h2, 5, &n2));
    return 0;
}
