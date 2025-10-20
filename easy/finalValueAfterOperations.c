// Final Value of Variable After Performing Operations

#include <stdio.h>

int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    for (int i = 0; i < operationsSize; i++) {
        // The middle character (index 1) determines if it's increment or decrement
        if (operations[i][1] == '+')
            x++;
        else
            x--;
    }
    return x;
}

int main()
{
    char* ops1[] = {"--X","X++","X++"};
    printf("%d\n", finalValueAfterOperations(ops1, 3)); // Output: 1

    char* ops2[] = {"++X","++X","X++"};
    printf("%d\n", finalValueAfterOperations(ops2, 3)); // Output: 3

    char* ops3[] = {"X++","++X","--X","X--"};
    printf("%d\n", finalValueAfterOperations(ops3, 4)); // Output: 0
}