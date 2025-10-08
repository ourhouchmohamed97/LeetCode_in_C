//  Successful Pairs of Spells and Potions

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Binary search for the first potion making spell * potion >= success
int lowerBound(int *potions, int potionsSize, long long minPotion) {
    int left = 0, right = potionsSize - 1;
    int ans = potionsSize; // Default (no valid potion)
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (potions[mid] >= minPotion) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int *result = (int *)malloc(spellsSize * sizeof(int));
    if (!result) return NULL;

    // Sort potions
    qsort(potions, potionsSize, sizeof(int), compare);

    // For each spell, find number of successful potions
    for (int i = 0; i < spellsSize; i++) {
        long long spell = spells[i];
        // Minimum potion strength required
        long long minPotion = (success + spell - 1) / spell; // ceil(success / spell)
        int idx = lowerBound(potions, potionsSize, minPotion);
        result[i] = potionsSize - idx;
    }

    return result;
}

int main() {
    int spells1[] = {5, 1, 3};
    int potions1[] = {1, 2, 3, 4, 5};
    long long success1 = 7;
    int returnSize1;
    int *result1 = successfulPairs(spells1, 3, potions1, 5, success1, &returnSize1);

    printf("Example 1 Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(", ");
    }
    printf("]\n");
    free(result1);

    int spells2[] = {3, 1, 2};
    int potions2[] = {8, 5, 8};
    long long success2 = 16;
    int returnSize2;
    int *result2 = successfulPairs(spells2, 3, potions2, 3, success2, &returnSize2);

    printf("Example 2 Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(", ");
    }
    printf("]\n");
    free(result2);

    return 0;
}