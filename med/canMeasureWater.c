// Water and Jug Problem

#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

bool canMeasureWater(int x, int y, int target) {
    if (target > x + y) return false;
    if (target == 0) return true;
    int g = gcd(x, y);
    return (target % g == 0);
}

int main() {
    printf("%d\n", canMeasureWater(3, 5, 4)); // true
    printf("%d\n", canMeasureWater(2, 6, 5)); // false
    printf("%d\n", canMeasureWater(1, 2, 3)); // true
    return 0;
}
