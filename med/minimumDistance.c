// Minimum Distance Between Three Equal Elements II

#include <limits.h>

int minimumDistance(int* nums, int numsSize) {
    int* last = (int*)malloc((numsSize + 1) * sizeof(int));
    int* second = (int*)malloc((numsSize + 1) * sizeof(int));
    
    for (int i = 0; i <= numsSize; i++) {
        last[i] = -1;
        second[i] = -1;
    }

    int min_dist = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (second[num] != -1) {
            int dist = i - second[num];
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
        second[num] = last[num];
        last[num] = i;
    }

    int result = (min_dist == INT_MAX) ? -1 : 2 * min_dist;
    
    free(last);
    free(second);
    return result;
}