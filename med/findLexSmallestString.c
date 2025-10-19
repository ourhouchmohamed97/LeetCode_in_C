// Lexicographically Smallest String After Applying Operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10000
#define MAX_HASH_SIZE 10000

typedef struct HashNode {
    char* key;
    struct HashNode* next;
} HashNode;

unsigned int hash(const char* str, int size) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % size;
        str++;
    }
    return hash;
}

bool contains(HashNode** hashTable, const char* str, int tableSize) {
    unsigned int idx = hash(str, tableSize);
    HashNode* node = hashTable[idx];
    while (node) {
        if (strcmp(node->key, str) == 0) return true;
        node = node->next;
    }
    return false;
}

void addToHash(HashNode** hashTable, const char* str, int tableSize) {
    unsigned int idx = hash(str, tableSize);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(str);
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

void freeHash(HashNode** hashTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
}

char* addOperation(const char* s, int a) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 1) {
            int digit = (s[i] - '0' + a) % 10;
            result[i] = '0' + digit;
        } else {
            result[i] = s[i];
        }
    }
    result[len] = '\0';
    return result;
}

char* rotateOperation(const char* s, int b) {
    int len = strlen(s);
    b = b % len;
    char* result = (char*)malloc(len + 1);
    
    for (int i = 0; i < b; i++) {
        result[i] = s[len - b + i];
    }
    for (int i = 0; i < len - b; i++) {
        result[b + i] = s[i];
    }
    result[len] = '\0';
    return result;
}

char* findLexSmallestString(char* s, int a, int b) {
    int len = strlen(s);
    
    char** queue = (char**)malloc(MAX_QUEUE_SIZE * sizeof(char*));
    int front = 0, rear = 0;
    
    HashNode** visited = (HashNode**)calloc(MAX_HASH_SIZE, sizeof(HashNode*));
    
    char* smallest = strdup(s);
    
    queue[rear++] = strdup(s);
    addToHash(visited, s, MAX_HASH_SIZE);
    
    while (front < rear) {
        char* current = queue[front++];
        if (strcmp(current, smallest) < 0) {
            free(smallest);
            smallest = strdup(current);
        }

        char* t1 = addOperation(current, a);
        char* t2 = rotateOperation(current, b);

        char* transformations[2] = {t1, t2};
        for (int i = 0; i < 2; i++) {
            char* transformed = transformations[i];
            if (!contains(visited, transformed, MAX_HASH_SIZE)) {
                addToHash(visited, transformed, MAX_HASH_SIZE);
                queue[rear++] = strdup(transformed);
            }
            free(transformed);
        }
        
        free(current);
    }
    for (int i = front; i < rear; i++) {
        free(queue[i]);
    }
    free(queue);
    freeHash(visited, MAX_HASH_SIZE);
    free(visited);
    
    return smallest;
}
