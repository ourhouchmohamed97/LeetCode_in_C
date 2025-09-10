// Water Bottles

#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange) {
    int drank = numBottles;
    int empty = numBottles;

    while (empty >= numExchange) {
        int newBottles = empty / numExchange;
        drank += newBottles;
        empty = empty % numExchange + newBottles;
    }

    return drank;
}

int main() {
    int numBottles, numExchange;

    // Example 1
    numBottles = 9;
    numExchange = 3;
    printf("Example 1: %d\n", numWaterBottles(numBottles, numExchange)); 
    // Expected: 13

    // Example 2
    numBottles = 15;
    numExchange = 4;
    printf("Example 2: %d\n", numWaterBottles(numBottles, numExchange)); 
    // Expected: 19

    // Custom input
    printf("Enter numBottles and numExchange: ");
    scanf("%d %d", &numBottles, &numExchange);
    printf("Result: %d\n", numWaterBottles(numBottles, numExchange));

    return 0;
}
