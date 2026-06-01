// Destroying Asteroids

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int), cmp);
    
    long long curr_mass = mass;
    
    for (int i = 0; i < asteroidsSize; i++) {
        if (curr_mass < asteroids[i]) {
            return false;
        }
        curr_mass += asteroids[i];
    }
    
    return true;
}
