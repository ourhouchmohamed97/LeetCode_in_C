// Minimum Absolute Distance Between Mirror Pairs

#include <stdlib.h>
#include <limits.h>

#define HASH_SIZE 262139 

typedef struct {
    int key;
    int val; 
} HashEntry;

int reverseNum(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int minMirrorPairDistance(int* nums, int numsSize) {
    HashEntry* table = (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));
    int min_dist = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        
        int idx = val % HASH_SIZE;
        while (table[idx].key != 0) {
            if (table[idx].key == val) {
                int dist = i - table[idx].val;
                if (dist < min_dist) {
                    min_dist = dist;
                }
                break;
            }
            idx = (idx + 1) % HASH_SIZE;
        }
        
        int r_val = reverseNum(val);
        idx = r_val % HASH_SIZE;
        while (table[idx].key != 0 && table[idx].key != r_val) {
            idx = (idx + 1) % HASH_SIZE;
        }
        table[idx].key = r_val;
        table[idx].val = i;
    }
    
    free(table);
    return min_dist == INT_MAX ? -1 : min_dist;
}