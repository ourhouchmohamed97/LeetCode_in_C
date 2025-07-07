// Maximum Number of Events That Can Be Attended

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Event;

int compareEvents(const void *a, const void *b) {
    Event *eventA = (Event *)a;
    Event *eventB = (Event *)b;
    if (eventA->start != eventB->start) {
        return eventA->start - eventB->start;
    } else {
        return eventA->end - eventB->end;
    }
}

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void initHeap(MinHeap *heap, int capacity) {
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[index] < heap->data[parent]) {
            swap(&heap->data[index], &heap->data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(MinHeap *heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(&heap->data[index], &heap->data[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void pushHeap(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));
    }
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int popHeap(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    int result = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return result;
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    Event *eventList = (Event *)malloc(eventsSize * sizeof(Event));
    for (int i = 0; i < eventsSize; i++) {
        eventList[i].start = events[i][0];
        eventList[i].end = events[i][1];
    }
    qsort(eventList, eventsSize, sizeof(Event), compareEvents);
    
    MinHeap heap;
    initHeap(&heap, eventsSize);
    
    int res = 0;
    int i = 0;
    int currentDay = 0;
    int maxDay = 0;
    for (int j = 0; j < eventsSize; j++) {
        if (eventList[j].end > maxDay) {
            maxDay = eventList[j].end;
        }
    }
    
    for (currentDay = 1; currentDay <= maxDay + 1; currentDay++) {
        while (i < eventsSize && eventList[i].start == currentDay) {
            pushHeap(&heap, eventList[i].end);
            i++;
        }
        
        while (heap.size > 0 && heap.data[0] < currentDay) {
            popHeap(&heap);
        }
        
        if (heap.size > 0) {
            popHeap(&heap);
            res++;
        }
    }
    
    free(eventList);
    free(heap.data);
    return res;
}

int main() {
    int eventsSize;
    scanf("%d", &eventsSize);
    
    int **events = (int **)malloc(eventsSize * sizeof(int *));
    for (int i = 0; i < eventsSize; i++) {
        events[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &events[i][0], &events[i][1]);
    }
    
    int *eventsColSize = (int *)malloc(eventsSize * sizeof(int));
    for (int i = 0; i < eventsSize; i++) {
        eventsColSize[i] = 2;
    }
    
    int result = maxEvents(events, eventsSize, eventsColSize);
    printf("%d\n", result);
    
    for (int i = 0; i < eventsSize; i++) {
        free(events[i]);
    }
    free(events);
    free(eventsColSize);
    
    return 0;
}