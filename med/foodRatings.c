// Design a Food Rating System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------ Structures ------------

typedef struct {
    char *food;
    char *cuisine;
    int rating;
} FoodInfo;

typedef struct {
    char *food;
    int rating;
} HeapNode;

typedef struct {
    HeapNode *arr;
    int size;
    int capacity;
} MaxHeap;

typedef struct {
    char *cuisine;
    MaxHeap *heap;

} CuisineHeap;

typedef struct {
    FoodInfo *foodsMap;     // food -> info
    CuisineHeap *cuisineMap; // cuisine -> heap
} FoodRatings;

// ------------ Heap Functions ------------

int compareHeapNodes(HeapNode a, HeapNode b) {
    if (a.rating != b.rating) return a.rating - b.rating;   // higher rating first
    return strcmp(b.food, a.food); // smaller lexicographically first
}

MaxHeap* createHeap(int cap) {
    MaxHeap *h = (MaxHeap*)malloc(sizeof(MaxHeap));
    h->arr = (HeapNode*)malloc(sizeof(HeapNode) * cap);
    h->size = 0;
    h->capacity = cap;
    return h;
}

void swap(HeapNode *a, HeapNode *b) {
    HeapNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyUp(MaxHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (compareHeapNodes(h->arr[idx], h->arr[parent]) > 0) {
            swap(&h->arr[idx], &h->arr[parent]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MaxHeap *h, int idx) {
    while (1) {
        int left = 2 * idx + 1, right = 2 * idx + 2, best = idx;
        if (left < h->size && compareHeapNodes(h->arr[left], h->arr[best]) > 0) best = left;
        if (right < h->size && compareHeapNodes(h->arr[right], h->arr[best]) > 0) best = right;
        if (best != idx) {
            swap(&h->arr[idx], &h->arr[best]);
            idx = best;
        } else break;
    }
}

void heapPush(MaxHeap *h, char *food, int rating) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->arr = realloc(h->arr, sizeof(HeapNode) * h->capacity);
    }
    h->arr[h->size].food = food;
    h->arr[h->size].rating = rating;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode heapTop(MaxHeap *h) {
    return h->arr[0];
}

void heapPop(MaxHeap *h) {
    if (h->size == 0) return;
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
}

// ------------ FoodRatings Methods ------------

FoodRatings* foodRatingsCreate(char** foods, int foodsSize, char** cuisines, int cuisinesSize, int* ratings, int ratingsSize) {
    FoodRatings* obj = malloc(sizeof(FoodRatings));
    obj->foodsMap = NULL;
    obj->cuisineMap = NULL;

    for (int i = 0; i < foodsSize; i++) {
        // Add to food map
        FoodInfo *fi = malloc(sizeof(FoodInfo));
        fi->food = strdup(foods[i]);
        fi->cuisine = strdup(cuisines[i]);
        fi->rating = ratings[i];
        HASH_ADD_KEYPTR(obj->foodsMap, fi->food, strlen(fi->food), fi);

        // Add to cuisine map
        CuisineHeap *ch;
        HASH_FIND_STR(obj->cuisineMap, cuisines[i], ch);
        if (!ch) {
            ch = malloc(sizeof(CuisineHeap));
            ch->cuisine = strdup(cuisines[i]);
            ch->heap = createHeap(16);
            HASH_ADD_KEYPTR(obj->cuisineMap, ch->cuisine, strlen(ch->cuisine), ch);
        }
        heapPush(ch->heap, fi->food, fi->rating);
    }
    return obj;
}

void foodRatingsChangeRating(FoodRatings* obj, char* food, int newRating) {
    FoodInfo *fi;
    HASH_FIND_STR(obj->foodsMap, food, fi);
    if (!fi) return;
    fi->rating = newRating;

    // push updated rating into cuisine heap
    CuisineHeap *ch;
    HASH_FIND_STR(obj->cuisineMap, fi->cuisine, ch);
    heapPush(ch->heap, fi->food, newRating);
}

char* foodRatingsHighestRated(FoodRatings* obj, char* cuisine) {
    CuisineHeap *ch;
    HASH_FIND_STR(obj->cuisineMap, cuisine, ch);
    if (!ch) return NULL;

    while (ch->heap->size > 0) {
        HeapNode top = heapTop(ch->heap);
        FoodInfo *fi;
        HASH_FIND_STR(obj->foodsMap, top.food, fi);
        if (fi && fi->rating == top.rating) return top.food;
        heapPop(ch->heap); // discard stale entry
    }
    return NULL;
}

int main() {
    char* foods[] = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    char* cuisines[] = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    int ratings[] = {9, 12, 8, 15, 14, 7};

    FoodRatings* obj = foodRatingsCreate(foods, 6, cuisines, 6, ratings, 6);

    printf("%s\n", foodRatingsHighestRated(obj, "korean"));   // kimchi
    printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // ramen

    foodRatingsChangeRating(obj, "sushi", 16);
    printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // sushi

    foodRatingsChangeRating(obj, "ramen", 16);
    printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // ramen

    foodRatingsFree(obj);
    return 0;
}
