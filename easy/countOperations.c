// Count Operations to Obtain Zero

#include <stdio.h>

int countOperations(int num1, int num2) {
    int count = 0;
    while (num1 > 0 && num2 > 0) {
        if (num1 >= num2)
            num1 -= num2;
        else
            num2 -= num1;
        count++;
    }
    return count;
}

int main() {
    printf("%d\n", countOperations(10, 4));
    printf("%d\n", countOperations(2, 3));
    printf("%d\n", countOperations(0, 5));
    return 0;
}
