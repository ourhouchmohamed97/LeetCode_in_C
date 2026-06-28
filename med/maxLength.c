// Find the Maximum Number of Elements in Subset

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100005
#define EMPTY -1

// Lightweight Hash Map for integer keys and integer values
typedef struct {
    int key;
    int val;
} MapItem;

typedef struct {
    MapItem items[MAX_SIZE];
} HashMap;

void map_init(HashMap* m) {
    for (int i = 0; i < MAX_SIZE; i++) {
        m->items[i].key = EMPTY;
        m->items[i].val = 0;
    }
}

// Simple hash function
static inline unsigned int hash_int(int key) {
    unsigned int k = (unsigned int)key;
    k = ((k >> 16) ^ k) * 0x45d9f3b;
    k = ((k >> 16) ^ k) * 0x45d9f3b;
    k = (k >> 16) ^ k;
    return k;
}

void map_put(HashMap* m, int key, int val) {
    unsigned int idx = hash_int(key) % MAX_SIZE;
    while (m->items[idx].key != EMPTY) {
        if (m->items[idx].key == key) {
            m->items[idx].val = val;
            return;
        }
        idx = (idx + 1) % MAX_SIZE;
    }
    m->items[idx].key = key;
    m->items[idx].val = val;
}

int* map_get(HashMap* m, int key) {
    unsigned int idx = hash_int(key) % MAX_SIZE;
    while (m->items[idx].key != EMPTY) {
        if (m->items[idx].key == key) {
            return &m->items[idx].val;
        }
        idx = (idx + 1) % MAX_SIZE;
    }
    return NULL;
}

void map_erase(HashMap* m, int key) {
    unsigned int idx = hash_int(key) % MAX_SIZE;
    while (m->items[idx].key != EMPTY) {
        if (m->items[idx].key == key) {
            m->items[idx].key = EMPTY;
            m->items[idx].val = 0;
            return;
        }
        idx = (idx + 1) % MAX_SIZE;
    }
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumLength(int* nums, int numsSize) {
    HashMap freq;
    map_init(&freq);

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        int* val = map_get(&freq, nums[i]);
        if (val) {
            (*val)++;
        } else {
            map_put(&freq, nums[i], 1);
        }
    }

    int res = 0;
    int* one_count = map_get(&freq, 1);
    if (one_count) {
        res = (*one_count - 1) | 1;
        map_erase(&freq, 1);
    }

    // Iterate over distinct elements
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq.items[i].key == EMPTY) continue;
        
        int n = 0;
        int x = freq.items[i].key;
        int sq = (int)sqrt((double)x);

        if ((long long)sq * sq == x) {
            int* sq_count = map_get(&freq, sq);
            if (sq_count && *sq_count > 1) {
                continue;
            }
        }

        // 31622^2 = 999,950,884 (which is just under 10^9, the constraint for this problem)
        while (x < 31623) {
            int* x_count = map_get(&freq, x);
            if (!x_count || *x_count <= 1) {
                break;
            }
            n += 2;
            // Check for integer overflow before squaring
            if (x > 31622) break; 
            x *= x;
        }

        int* final_count = map_get(&freq, x);
        int add = (final_count != NULL) << 1;
        res = MAX(res, n + (add - 1));
    }

    return res;
}