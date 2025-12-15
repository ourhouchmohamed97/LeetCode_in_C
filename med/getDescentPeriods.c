// Number of Smooth Descent Periods of a Stock

#include <stdio.h>
#include <stdlib.h>

long long getDescentPeriods(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    long long totalCount = 0;
    int currentLength = 1;  // Each day is at least a period of length 1
    
    for (int i = 1; i < pricesSize; i++) {
        // Check if current price continues smooth descent
        if (prices[i - 1] - prices[i] == 1) {
            currentLength++;
        } else {
            // Calculate contribution of completed descent period
            totalCount += (long long)currentLength * (currentLength + 1) / 2;
            currentLength = 1;  // Reset for new period
        }
    }
    
    // Add the last period's contribution
    totalCount += (long long)currentLength * (currentLength + 1) / 2;
    
    return totalCount;
}

int main() {
    // Example 1: [3, 2, 1, 4]
    int prices1[] = {3, 2, 1, 4};
    printf("Output: %lld\n", getDescentPeriods(prices1, 4));  // Expected: 7
    
    // Example 2: [8, 6, 7]
    int prices2[] = {8, 6, 7};
    printf("Output: %lld\n", getDescentPeriods(prices2, 3));  // Expected: 4
    
    // Example 3: [1]
    int prices3[] = {1};
    printf("Output: %lld\n", getDescentPeriods(prices3, 1));  // Expected: 1
    
    return 0;
}
