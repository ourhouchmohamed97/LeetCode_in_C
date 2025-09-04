// Find Closest Person

#include <stdio.h>
#include <stdlib.h> // For abs()

int findClosest(int x, int y, int z) {
    int dist1 = abs(x - z);
    int dist2 = abs(y - z);
    
    if (dist1 < dist2) return 1;
    if (dist2 < dist1) return 2;
    return 0;
}

int main() {
    // Test cases from the examples
    printf("Test Case 1: x=2, y=7, z=4\n");
    printf("Output: %d\n", findClosest(2, 7, 4)); // Expected: 1
    
    printf("Test Case 2: x=2, y=5, z=6\n");
    printf("Output: %d\n", findClosest(2, 5, 6)); // Expected: 2
    
    printf("Test Case 3: x=1, y=5, z=3\n");
    printf("Output: %d\n", findClosest(1, 5, 3)); // Expected: 0
    
    // Optional: Interactive input
    int x, y, z;
    printf("\nEnter positions x, y, z (separated by spaces): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Output: %d\n", findClosest(x, y, z));
    
    return 0;
}