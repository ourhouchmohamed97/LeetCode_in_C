// Minimum Distance to the Target Element

#include <limits.h>

int getMinDistance(int* nums, int numsSize, int target, int start) {
    int min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            int dist = abs(start - i);
            if (dist < min) {
                min = dist;
            }
        }
    }

    return min;
}