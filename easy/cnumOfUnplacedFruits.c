// Fruits Into Baskets II

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    bool* used = (bool*)calloc(basketsSize, sizeof(bool));
    int unplaced = 0;
    
    for (int i = 0; i < fruitsSize; i++) {
        int fruit = fruits[i];
        bool placed = false;
        for (int j = 0; j < basketsSize; j++) {
            if (!used[j] && baskets[j] >= fruit) {
                used[j] = true;
                placed = true;
                break;
            }
        }
        if (!placed) {
            unplaced++;
        }
    }
    
    free(used);
    return unplaced;
}

int main() {
    // Example 1
    int fruits1[] = {4, 2, 5};
    int baskets1[] = {3, 5, 4};
    int fruitsSize1 = sizeof(fruits1) / sizeof(fruits1[0]);
    int basketsSize1 = sizeof(baskets1) / sizeof(baskets1[0]);
    int result1 = numOfUnplacedFruits(fruits1, fruitsSize1, baskets1, basketsSize1);
    printf("Example 1 Output: %d\n", result1); // Expected output: 1

    // Example 2
    int fruits2[] = {3, 6, 1};
    int baskets2[] = {6, 4, 7};
    int fruitsSize2 = sizeof(fruits2) / sizeof(fruits2[0]);
    int basketsSize2 = sizeof(baskets2) / sizeof(baskets2[0]);
    int result2 = numOfUnplacedFruits(fruits2, fruitsSize2, baskets2, basketsSize2);
    printf("Example 2 Output: %d\n", result2); // Expected output: 0

    return 0;
}