// Total Distance Traveled

int distanceTraveled(int mainTank, int additionalTank) {
    int distance = 0;

    while (mainTank >= 5) {
        mainTank -= 5;        // Use 5 liters
        distance += 5 * 10;   // 5 liters → 50 km

        if (additionalTank > 0) {
            mainTank += 1;    // Transfer 1 liter
            additionalTank--; // Decrease additional tank
        }
    }

    // Add distance for remaining fuel
    distance += mainTank * 10;

    return distance;
}

#include <stdio.h>

int main() {
    printf("Example 1: %d\n", distanceTraveled(5, 10)); // Expected 60
    printf("Example 2: %d\n", distanceTraveled(1, 2));  // Expected 10
    printf("Example 3: %d\n", distanceTraveled(9, 2));  // Check extra case → 110
    return 0;
}
