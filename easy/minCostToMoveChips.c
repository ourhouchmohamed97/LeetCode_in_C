// Minimum Cost to Move Chips to The Same Position

#include <stdio.h>

int minCostToMoveChips(int* position, int positionSize) {
    int even_count = 0;
    int odd_count = 0;
    
    for (int i = 0; i < positionSize; i++) {
        if (position[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    return (even_count < odd_count) ? even_count : odd_count;
}

int main() {
    // Test case 1: position = [1,2,3]
    int position1[] = {1, 2, 3};
    int size1 = sizeof(position1) / sizeof(position1[0]);
    int result1 = minCostToMoveChips(position1, size1);
    printf("Test case 1: [1,2,3]\n");
    printf("Expected output: 1\n");
    printf("Actual output: %d\n\n", result1);

    // Test case 2: position = [2,2,2,3,3]
    int position2[] = {2, 2, 2, 3, 3};
    int size2 = sizeof(position2) / sizeof(position2[0]);
    int result2 = minCostToMoveChips(position2, size2);
    printf("Test case 2: [2,2,2,3,3]\n");
    printf("Expected output: 2\n");
    printf("Actual output: %d\n\n", result2);

    // Test case 3: position = [1,1000000000]
    int position3[] = {1, 1000000000};
    int size3 = sizeof(position3) / sizeof(position3[0]);
    int result3 = minCostToMoveChips(position3, size3);
    printf("Test case 3: [1,1000000000]\n");
    printf("Expected output: 1\n");
    printf("Actual output: %d\n\n", result3);

    return 0;
}
