// Pass the Pillow

#include <stdio.h>

int passThePillow(int n, int time) {
    int cycle = time % (2 * (n - 1));
    if (cycle < n - 1) {
        return 1 + cycle;
    } else {
        return n - (cycle - (n - 1));
    }
}

int main() {
    int n, time;
    
    // Test case 1
    n = 4;
    time = 5;
    printf("Person holding the pillow at time %d: %d\n", time, passThePillow(n, time));
    
    // Test case 2
    n = 3;
    time = 2;
    printf("Person holding the pillow at time %d: %d\n", time, passThePillow(n, time));
    
    // Test case 3
    n = 5;
    time = 8;
    printf("Person holding the pillow at time %d: %d\n", time, passThePillow(n, time));
    
    // Test case 4
    n = 6;
    time = 12;
    printf("Person holding the pillow at time %d: %d\n", time, passThePillow(n, time));

    return 0;
}
