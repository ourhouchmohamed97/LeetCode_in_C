// Distribute Candies to People

#include <stdio.h>
#include <stdlib.h>

int* distributeCandies(int candies, int num_people, int* returnSize) {
    *returnSize = num_people;
    int* result = (int*)calloc(num_people, sizeof(int));
    int give = 1;
    int i = 0;
    while (candies > 0) {
        if (candies < give) {
            result[i] += candies;
            break;
        } else {
            result[i] += give;
            candies -= give;
            give++;
            i = (i + 1) % num_people;
        }
    }
    return result;
}

int main() {
    int candies1 = 7;
    int num_people1 = 4;
    int returnSize1;
    int* result1 = distributeCandies(candies1, num_people1, &returnSize1);
    printf("Example 1:\n");
    printf("Input: candies = %d, num_people = %d\n", candies1, num_people1);
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result1);

    int candies2 = 10;
    int num_people2 = 3;
    int returnSize2;
    int* result2 = distributeCandies(candies2, num_people2, &returnSize2);
    printf("Example 2:\n");
    printf("Input: candies = %d, num_people = %d\n", candies2, num_people2);
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result2);

    return 0;
}