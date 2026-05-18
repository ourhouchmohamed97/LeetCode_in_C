// Jump Game IV

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int* data;
    int size;
    int cap;
    int used;
    struct Node* next;
} Node;

#define HASH_SIZE 200003
unsigned int hashKey(int x) {
    return ((unsigned int)x) % HASH_SIZE;
}
Node* findNode(Node** map, int key) {
    unsigned int h = hashKey(key);
    Node* cur = map[h];
    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void addIndex(Node** map, int key, int idx) {
    unsigned int h = hashKey(key);
    Node* node = findNode(map, key);
    if (!node) {
        node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->size = 0;
        node->cap = 4;
        node->used = 0;
        node->data = (int*)malloc(sizeof(int) * node->cap);
        node->next = map[h];
        map[h] = node;
    }
    if (node->size == node->cap) {
        node->cap *= 2;
        node->data = (int*)realloc(node->data, sizeof(int) * node->cap);
    }
    node->data[node->size++] = idx;
}
int minJumps(int* arr, int arrSize) {
    int n = arrSize;
    if (n == 1)
        return 0;
    Node** map = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    for (int i = 0; i < n; i++) {
        addIndex(map, arr[i], i);
    }
    int* q = (int*)malloc(sizeof(int) * n);
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int front = 0;
    int back = 0;
    int cnt = 0;
    q[back++] = 0;
    visited[0] = true;
    while (front < back) {
        int size = back - front;
        while (size--) {
            int idx = q[front++];
            if (idx == n - 1) {
                free(q);
                free(visited);
                return cnt;
            }
            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q[back++] = idx - 1;
            }
            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q[back++] = idx + 1;
            }
            Node* node = findNode(map, arr[idx]);
            if (node && !node->used) {
                for (int i = 0; i < node->size; i++) {
                    int nxt = node->data[i];
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q[back++] = nxt;
                    }
                }
                node->used = 1;
            }
        }
        cnt++;
    }
    free(q);
    free(visited);
    return -1;
}