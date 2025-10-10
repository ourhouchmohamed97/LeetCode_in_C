// K Items With the Maximum Sum

#include <stdio.h>

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    if (k <= numOnes)
        return k;
    else if (k <= numOnes + numZeros)
        return numOnes;
    else
        return numOnes - (k - numOnes - numZeros);
}

int main() {
    printf("%d\n", kItemsWithMaximumSum(3, 2, 0, 2)); // Output: 2
    printf("%d\n", kItemsWithMaximumSum(3, 2, 0, 4)); // Output: 3
    printf("%d\n", kItemsWithMaximumSum(3, 1, 2, 5)); // Output: 2
    return 0;
}