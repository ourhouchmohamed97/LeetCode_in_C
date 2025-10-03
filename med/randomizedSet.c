// Insert Delete GetRandom O(1)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HASH_SIZE 1009

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

typedef struct {
    int* arr;
    int size;
    int capacity;
    Node** map;
} RandomizedSet;

int hash(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->capacity = 1000;
    obj->size = 0;
    obj->arr = (int*)malloc(sizeof(int) * obj->capacity);
    obj->map = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    srand(time(NULL));
    return obj;
}

Node* findNode(Node* head, int key) {
    while (head) {
        if (head->key == key) return head;
        head = head->next;
    }
    return NULL;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int h = hash(val);
    if (findNode(obj->map[h], val)) return false;
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (int*)realloc(obj->arr, sizeof(int) * obj->capacity);
    }
    obj->arr[obj->size] = val;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = val;
    newNode->index = obj->size;
    newNode->next = obj->map[h];
    obj->map[h] = newNode;
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int h = hash(val);
    Node* prev = NULL;
    Node* curr = obj->map[h];
    while (curr) {
        if (curr->key == val) {
            int idx = curr->index;
            int lastVal = obj->arr[obj->size - 1];
            obj->arr[idx] = lastVal;
            int h2 = hash(lastVal);
            Node* node = obj->map[h2];
            while (node) {
                if (node->key == lastVal) {
                    node->index = idx;
                    break;
                }
                node = node->next;
            }
            obj->size--;
            if (prev) prev->next = curr->next;
            else obj->map[h] = curr->next;
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int r = rand() % obj->size;
    return obj->arr[r];
}

void randomizedSetFree(RandomizedSet* obj) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = obj->map[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(obj->map);
    free(obj->arr);
    free(obj);
}

int main() {
    RandomizedSet* randomizedSet = randomizedSetCreate();
    printf("%d\n", randomizedSetInsert(randomizedSet, 1));
    printf("%d\n", randomizedSetRemove(randomizedSet, 2));
    printf("%d\n", randomizedSetInsert(randomizedSet, 2));
    printf("%d\n", randomizedSetGetRandom(randomizedSet));
    printf("%d\n", randomizedSetRemove(randomizedSet, 1));
    printf("%d\n", randomizedSetInsert(randomizedSet, 2));
    printf("%d\n", randomizedSetGetRandom(randomizedSet));
    randomizedSetFree(randomizedSet);
    return 0;
}
