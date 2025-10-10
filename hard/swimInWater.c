// Swim in Rising Water

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y, h;
} Cell;

typedef struct {
    Cell *arr;
    int size, capacity;
} MinHeap;

void swap(Cell *a, Cell *b) {
    Cell temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->arr = malloc(sizeof(Cell) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heapPush(MinHeap *heap, Cell c) {
    heap->arr[heap->size++] = c;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->arr[parent].h <= heap->arr[i].h) break;
        swap(&heap->arr[parent], &heap->arr[i]);
        i = parent;
    }
}

Cell heapPop(MinHeap *heap) {
    Cell top = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    int i = 0;
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < heap->size && heap->arr[l].h < heap->arr[smallest].h)
            smallest = l;
        if (r < heap->size && heap->arr[r].h < heap->arr[smallest].h)
            smallest = r;
        if (smallest == i) break;
        swap(&heap->arr[i], &heap->arr[smallest]);
        i = smallest;
    }
    return top;
}

bool heapEmpty(MinHeap *heap) {
    return heap->size == 0;
}

int swimInWater(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    bool visited[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    MinHeap *heap = createHeap(n * n);
    heapPush(heap, (Cell){0, 0, grid[0][0]});
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;

    while (!heapEmpty(heap)) {
        Cell curr = heapPop(heap);
        int x = curr.x, y = curr.y, h = curr.h;
        ans = (ans > h) ? ans : h;

        if (x == n - 1 && y == n - 1)
            return ans;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                heapPush(heap, (Cell){nx, ny, grid[nx][ny]});
            }
        }
    }

    return ans;
}

int main() {
    // Example 1
    int grid1Data[2][2] = {{0, 2}, {1, 3}};
    int* grid1[2];
    int colSize1 = 2;
    for (int i = 0; i < 2; i++) grid1[i] = grid1Data[i];

    int result1 = swimInWater(grid1, 2, &colSize1);
    printf("Example 1 Output: %d\n", result1); // Expected: 3

    // Example 2
    int grid2Data[5][5] = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    int* grid2[5];
    int colSize2 = 5;
    for (int i = 0; i < 5; i++) grid2[i] = grid2Data[i];

    int result2 = swimInWater(grid2, 5, &colSize2);
    printf("Example 2 Output: %d\n", result2); // Expected: 16

    return 0;
}