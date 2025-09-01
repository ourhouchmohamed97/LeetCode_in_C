// Maximum Average Pass Ratio

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double benefit;
    int pass;
    int total;
} Class;

void swap(Class* a, Class* b) {
    Class temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    Class* heap;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->heap = (Class*)malloc(capacity * sizeof(Class));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    return maxHeap;
}

void heapifyUp(MaxHeap* maxHeap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && maxHeap->heap[index].benefit > maxHeap->heap[parent].benefit) {
        swap(&maxHeap->heap[index], &maxHeap->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(MaxHeap* maxHeap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < maxHeap->size && maxHeap->heap[left].benefit > maxHeap->heap[largest].benefit) {
        largest = left;
    }
    if (right < maxHeap->size && maxHeap->heap[right].benefit > maxHeap->heap[largest].benefit) {
        largest = right;
    }
    if (largest != index) {
        swap(&maxHeap->heap[index], &maxHeap->heap[largest]);
        heapifyDown(maxHeap, largest);
    }
}

void push(MaxHeap* maxHeap, Class value) {
    if (maxHeap->size == maxHeap->capacity) {
        return;
    }
    maxHeap->heap[maxHeap->size] = value;
    heapifyUp(maxHeap, maxHeap->size);
    maxHeap->size++;
}

Class pop(MaxHeap* maxHeap) {
    Class root = maxHeap->heap[0];
    maxHeap->heap[0] = maxHeap->heap[--maxHeap->size];
    heapifyDown(maxHeap, 0);
    return root;
}

double calculateBenefit(int pass, int total) {
    return (double)(pass + 1) / (total + 1) - (double)pass / total;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    MaxHeap* maxHeap = createMaxHeap(classesSize);
    for (int i = 0; i < classesSize; i++) {
        int pass = classes[i][0];
        int total = classes[i][1];
        double benefit = calculateBenefit(pass, total);
        Class c = { benefit, pass, total };
        push(maxHeap, c);
    }
    
    for (int i = 0; i < extraStudents; i++) {
        Class c = pop(maxHeap);
        c.pass++;
        c.total++;
        c.benefit = calculateBenefit(c.pass, c.total);
        push(maxHeap, c);
    }
    
    double totalRatio = 0.0;
    for (int i = 0; i < classesSize; i++) {
        Class c = maxHeap->heap[i];
        totalRatio += (double)c.pass / c.total;
    }
    
    free(maxHeap->heap);
    free(maxHeap);
    
    return totalRatio / classesSize;
}

int main() {
    // Example 1
    int classes1[][2] = {{1,2}, {3,5}, {2,2}};
    int classesSize1 = 3;
    int classesColSize1[] = {2, 2, 2};
    int extraStudents1 = 2;
    int** classesArray1 = (int**)malloc(classesSize1 * sizeof(int*));
    for (int i = 0; i < classesSize1; i++) {
        classesArray1[i] = (int*)malloc(2 * sizeof(int));
        classesArray1[i][0] = classes1[i][0];
        classesArray1[i][1] = classes1[i][1];
    }
    double result1 = maxAverageRatio(classesArray1, classesSize1, classesColSize1, extraStudents1);
    printf("Example 1 Output: %.5f\n", result1);
    
    for (int i = 0; i < classesSize1; i++) {
        free(classesArray1[i]);
    }
    free(classesArray1);
    
    // Example 2
    int classes2[][2] = {{2,4}, {3,9}, {4,5}, {2,10}};
    int classesSize2 = 4;
    int classesColSize2[] = {2, 2, 2, 2};
    int extraStudents2 = 4;
    int** classesArray2 = (int**)malloc(classesSize2 * sizeof(int*));
    for (int i = 0; i < classesSize2; i++) {
        classesArray2[i] = (int*)malloc(2 * sizeof(int));
        classesArray2[i][0] = classes2[i][0];
        classesArray2[i][1] = classes2[i][1];
    }
    double result2 = maxAverageRatio(classesArray2, classesSize2, classesColSize2, extraStudents2);
    printf("Example 2 Output: %.5f\n", result2);
    
    for (int i = 0; i < classesSize2; i++) {
        free(classesArray2[i]);
    }
    free(classesArray2);
    
    return 0;
}