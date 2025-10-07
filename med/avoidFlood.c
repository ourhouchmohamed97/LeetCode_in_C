// Avoid Flood in The City

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} MapItem;

typedef struct {
    MapItem *items;
    int capacity;
} HashMap;

int hash(int key, int cap) {
    return (key * 2654435761u) % cap;
}

void initHashMap(HashMap *map, int capacity) {
    map->capacity = capacity * 2;
    map->items = calloc(map->capacity, sizeof(MapItem));
    for (int i = 0; i < map->capacity; i++) map->items[i].key = -1;
}

void freeHashMap(HashMap *map) {
    free(map->items);
}

int hashFind(HashMap *map, int key) {
    int idx = hash(key, map->capacity);
    for (int i = 0; i < map->capacity; i++) {
        int cur = (idx + i) % map->capacity;
        if (map->items[cur].key == -1) return -1;
        if (map->items[cur].key == key) return map->items[cur].value;
    }
    return -1;
}

void hashInsert(HashMap *map, int key, int value) {
    int idx = hash(key, map->capacity);
    for (int i = 0; i < map->capacity; i++) {
        int cur = (idx + i) % map->capacity;
        if (map->items[cur].key == -1 || map->items[cur].key == key) {
            map->items[cur].key = key;
            map->items[cur].value = value;
            return;
        }
    }
}

int binarySearchGreater(int *arr, int size, int target, char *used) {
    int l = 0, r = size - 1, result = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > target) {
            result = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    // skip already used dry days
    while (result != -1 && result < size && used[result]) result++;
    if (result >= size) return -1;
    return result;
}

int* avoidFlood(int* rains, int n, int* returnSize) {
    *returnSize = n;
    int* ans = malloc(sizeof(int) * n);
    int* dryDays = malloc(sizeof(int) * n);
    char* used = calloc(n, sizeof(char)); // mark used dry days
    int drySize = 0;

    HashMap map;
    initHashMap(&map, n);

    for (int i = 0; i < n; i++) {
        if (rains[i] == 0) {
            dryDays[drySize++] = i;
            ans[i] = 1; // placeholder
        } else {
            int lake = rains[i];
            ans[i] = -1;
            int last = hashFind(&map, lake);
            if (last != -1) {
                int pos = binarySearchGreater(dryDays, drySize, last, used);
                if (pos == -1) {
                    // flood: impossible
                    free(ans); free(dryDays); free(used); freeHashMap(&map);
                    *returnSize = 0;
                    return NULL;
                }
                ans[dryDays[pos]] = lake;
                used[pos] = 1; // mark dry day used
            }
            hashInsert(&map, lake, i);
        }
    }

    free(dryDays);
    free(used);
    freeHashMap(&map);
    return ans;
}

// ---- Test ----
void printArray(int *arr, int size) {
    if (!arr || size == 0) { printf("[]\n"); return; }
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int rains1[] = {1,2,3,4};
    int size1; printArray(avoidFlood(rains1, 4, &size1), size1);

    int rains2[] = {1,2,0,0,2,1};
    int size2; printArray(avoidFlood(rains2, 6, &size2), size2);

    int rains3[] = {1,2,0,1,2};
    int size3; printArray(avoidFlood(rains3, 5, &size3), size3);

    return 0;
}
