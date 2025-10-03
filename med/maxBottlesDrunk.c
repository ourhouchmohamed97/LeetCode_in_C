// Water Bottles II

#include <stdio.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
    int full = numBottles;
    int empty = 0;
    int drunk = 0;
    while (full > 0) {
        drunk += full;
        empty += full;
        full = 0;
        if (empty >= numExchange) {
            empty -= numExchange;
            full = 1;
            numExchange++;
        }
    }
    return drunk;
}

int main() {
    printf("%d\n", maxBottlesDrunk(13, 6));
    printf("%d\n", maxBottlesDrunk(10, 3));
    return 0;
}
