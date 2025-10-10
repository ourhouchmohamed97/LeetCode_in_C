// Calculate Delayed Arrival Time

#include <stdio.h>

int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    int time = arrivalTime + delayedTime;
    if (time == 24)
        return 0;
    else if (time > 24)
        return time - 24;
    return time;
}

int main() {
    int arrivalTime, delayedTime;

    // Ask user for input
    printf("Enter arrival time (0-23): ");
    scanf("%d", &arrivalTime);

    printf("Enter delayed time (hours): ");
    scanf("%d", &delayedTime);

    int result = findDelayedArrivalTime(arrivalTime, delayedTime);
    printf("Delayed arrival time: %d\n", result);

    // Example test cases
    printf("\n--- Example Tests ---\n");
    printf("Case 1: arrivalTime = 15, delayedTime = 5 → %d\n", findDelayedArrivalTime(15, 5)); // Expected 20
    printf("Case 2: arrivalTime = 23, delayedTime = 2 → %d\n", findDelayedArrivalTime(23, 2)); // Expected 1
    printf("Case 3: arrivalTime = 20, delayedTime = 4 → %d\n", findDelayedArrivalTime(20, 4)); // Expected 0

    return 0;
}
