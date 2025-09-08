// Bulb Switcher

#include <math.h>

int bulbSwitch(int n) {
    return (int)sqrt(n);
}

int main() {
    // Test case 1: n = 3
    int n1 = 3;
    printf("Test 1: n = %d, Bulbs on = %d\n", n1, bulbSwitch(n1));
    
    // Test case 2: n = 0
    int n2 = 0;
    printf("Test 2: n = %d, Bulbs on = %d\n", n2, bulbSwitch(n2));

    // Test case 3: n = 1
    int n3 = 1;
    printf("Test 3: n = %d, Bulbs on = %d\n", n3, bulbSwitch(n3));

    // Test case 4: n = 16
    int n4 = 16;
    printf("Test 4: n = %d, Bulbs on = %d\n", n4, bulbSwitch(n4));

    // Test case 5: n = 100
    int n5 = 100;
    printf("Test 5: n = %d, Bulbs on = %d\n", n5, bulbSwitch(n5));

    return 0;
}