// Design Task Manager

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ---------------- Task Struct ----------------
typedef struct {
    int userId;
    int taskId;
    int priority;
} Task;

// ---------------- Heap Struct ----------------
typedef struct {
    Task* arr;      // max-heap of tasks
    int size;
    int capacity;
} MaxHeap;

// ---------------- Map Entry ----------------
typedef struct {
    int taskId;
    int userId;
    int priority;
    int heapIndex;  // position in heap
    bool valid;
} MapEntry;

// ---------------- TaskManager ----------------
typedef struct {
    MaxHeap* heap;
    MapEntry* map;  // array acting as hash map
    int mapCap;
} TaskManager;

// ---------------- Utility: Heap Functions ----------------
static void swap(MaxHeap* heap, int i, int j, MapEntry* map) {
    Task t = heap->arr[i];
    heap->arr[i] = heap->arr[j];
    heap->arr[j] = t;

    map[heap->arr[i].taskId].heapIndex = i;
    map[heap->arr[j].taskId].heapIndex = j;
}

static bool better(Task a, Task b) {
    if (a.priority != b.priority)
        return a.priority > b.priority; // higher priority first
    return a.taskId > b.taskId;         // tie-break on taskId
}

static void heapifyUp(MaxHeap* heap, int i, MapEntry* map) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (!better(heap->arr[i], heap->arr[parent])) break;
        swap(heap, i, parent, map);
        i = parent;
    }
}

static void heapifyDown(MaxHeap* heap, int i, MapEntry* map) {
    int size = heap->size;
    while (1) {
        int left = 2*i + 1, right = 2*i + 2, best = i;
        if (left < size && better(heap->arr[left], heap->arr[best])) best = left;
        if (right < size && better(heap->arr[right], heap->arr[best])) best = right;
        if (best == i) break;
        swap(heap, i, best, map);
        i = best;
    }
}

// ---------------- Heap API ----------------
static MaxHeap* createHeap(int cap) {
    MaxHeap* h = malloc(sizeof(MaxHeap));
    h->arr = malloc(sizeof(Task) * cap);
    h->size = 0;
    h->capacity = cap;
    return h;
}

static void push(MaxHeap* heap, Task t, MapEntry* map) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->arr = realloc(heap->arr, sizeof(Task) * heap->capacity);
    }
    heap->arr[heap->size] = t;
    map[t.taskId].heapIndex = heap->size;
    heapifyUp(heap, heap->size, map);
    heap->size++;
}

static Task pop(MaxHeap* heap, MapEntry* map) {
    Task top = heap->arr[0];
    swap(heap, 0, heap->size-1, map);
    heap->size--;
    heapifyDown(heap, 0, map);
    return top;
}

// ---------------- Map Expansion ----------------
static void ensureMapCapacity(TaskManager* tm, int taskId) {
    if (taskId >= tm->mapCap) {
        int newCap = tm->mapCap;
        while (newCap <= taskId) newCap *= 2;
        tm->map = realloc(tm->map, sizeof(MapEntry) * newCap);
        for (int i = tm->mapCap; i < newCap; i++) {
            tm->map[i].valid = false;
        }
        tm->mapCap = newCap;
    }
}

// ---------------- TaskManager API ----------------
TaskManager* taskManagerCreate(int** tasks, int tasksSize, int* tasksColSize) {
    TaskManager* tm = malloc(sizeof(TaskManager));
    tm->heap = createHeap(64);
    tm->mapCap = 1024; // start with something reasonable
    tm->map = calloc(tm->mapCap, sizeof(MapEntry));

    for (int i = 0; i < tasksSize; i++) {
        int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
        ensureMapCapacity(tm, taskId);
        Task t = (Task){userId, taskId, priority};
        tm->map[taskId] = (MapEntry){taskId, userId, priority, -1, true};
        push(tm->heap, t, tm->map);
    }
    return tm;
}

void taskManagerAdd(TaskManager* obj, int userId, int taskId, int priority) {
    ensureMapCapacity(obj, taskId);
    Task t = (Task){userId, taskId, priority};
    obj->map[taskId] = (MapEntry){taskId, userId, priority, -1, true};
    push(obj->heap, t, obj->map);
}

void taskManagerEdit(TaskManager* obj, int taskId, int newPriority) {
    ensureMapCapacity(obj, taskId);
    MapEntry* e = &obj->map[taskId];
    int idx = e->heapIndex;
    obj->heap->arr[idx].priority = newPriority;
    e->priority = newPriority;

    heapifyUp(obj->heap, idx, obj->map);
    heapifyDown(obj->heap, idx, obj->map);
}

void taskManagerRmv(TaskManager* obj, int taskId) {
    ensureMapCapacity(obj, taskId);
    MapEntry* e = &obj->map[taskId];
    int idx = e->heapIndex;

    swap(obj->heap, idx, obj->heap->size - 1, obj->map);
    obj->heap->size--;
    heapifyUp(obj->heap, idx, obj->map);
    heapifyDown(obj->heap, idx, obj->map);

    e->valid = false;
}

int taskManagerExecTop(TaskManager* obj) {
    if (obj->heap->size == 0) return -1;

    Task top = pop(obj->heap, obj->map);
    obj->map[top.taskId].valid = false;
    return top.userId;
}

void taskManagerFree(TaskManager* obj) {
    free(obj->heap->arr);
    free(obj->heap);
    free(obj->map);
    free(obj);
}

int main() {
    // Initialize tasks: [[1,101,10], [2,102,20], [3,103,15]]
    int t1[] = {1, 101, 10};
    int t2[] = {2, 102, 20};
    int t3[] = {3, 103, 15};
    int* tasks[] = {t1, t2, t3};
    int colSize[] = {3, 3, 3};

    TaskManager* taskManager = taskManagerCreate(tasks, 3, colSize);

    // add(4, 104, 5)
    taskManagerAdd(taskManager, 4, 104, 5);

    // edit(102, 8)
    taskManagerEdit(taskManager, 102, 8);

    // execTop() -> expect 3 (task 103 has priority 15)
    printf("%d\n", taskManagerExecTop(taskManager));

    // rmv(101)
    taskManagerRmv(taskManager, 101);

    // add(5, 105, 15)
    taskManagerAdd(taskManager, 5, 105, 15);

    // execTop() -> expect 5 (task 105 with priority 15)
    printf("%d\n", taskManagerExecTop(taskManager));

    taskManagerFree(taskManager);
    return 0;
}
