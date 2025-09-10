// Count Odd Numbers in an Interval Range

#include <stdio.h>

int countOdds(int low, int high){
    int i = low;
    int odd = 0;
    while (i <= high)
    {
        if (i % 2 != 0)
            odd++;
        i++;
    }
    return odd;
}

int main() {
    int low, high;

    // Example 1
    low = 3;
    high = 7;
    printf("countOdds(%d, %d) = %d\n", low, high, countOdds(low, high)); 
    // Expected: 3 (3,5,7)

    // Example 2
    low = 8;
    high = 10;
    printf("countOdds(%d, %d) = %d\n", low, high, countOdds(low, high)); 
    // Expected: 1 (9)

    // Custom input from user
    printf("Enter low and high: ");
    scanf("%d %d", &low, &high);
    printf("countOdds(%d, %d) = %d\n", low, high, countOdds(low, high));

    return 0;
}