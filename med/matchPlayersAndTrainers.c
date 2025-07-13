// Maximum Matching of Players With Trainers

#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), compare);
    qsort(trainers, trainersSize, sizeof(int), compare);
    
    int i = 0, j = 0, matches = 0;
    
    while (i < playersSize && j < trainersSize) {
        if (players[i] <= trainers[j]) {
            matches++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    return matches;
}

int main() {
    int players1[] = {4, 7, 9};
    int trainers1[] = {8, 2, 5, 8};
    int playersSize1 = sizeof(players1) / sizeof(players1[0]);
    int trainersSize1 = sizeof(trainers1) / sizeof(trainers1[0]);
    
    int result1 = matchPlayersAndTrainers(players1, playersSize1, trainers1, trainersSize1);
    printf("Example 1 Output: %d\n", result1);  // Expected output: 2
    
    int players2[] = {1, 1, 1};
    int trainers2[] = {10};
    int playersSize2 = sizeof(players2) / sizeof(players2[0]);
    int trainersSize2 = sizeof(trainers2) / sizeof(trainers2[0]);
    
    int result2 = matchPlayersAndTrainers(players2, playersSize2, trainers2, trainersSize2);
    printf("Example 2 Output: %d\n", result2);  // Expected output: 1
    
    return 0;
}