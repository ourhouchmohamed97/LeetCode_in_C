// Path Existence Queries in a Graph I

#include <stdlib.h>
#include <stdbool.h>

bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* component = (int*)calloc(n, sizeof(int));
    int compNo = 0;
    
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] > maxDiff) {
            compNo++;
        }
        component[i] = compNo;
    }
    
    bool* sol = (bool*)malloc(queriesSize * sizeof(bool));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        sol[i] = (component[queries[i][0]] == component[queries[i][1]]);
    }
    
    free(component);
    return sol;
}