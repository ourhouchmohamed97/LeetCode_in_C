// Count Largest Group

#include <stdio.h>
#include <stdlib.h>

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countLargestGroup(int n) {
    // The maximum digit sum for n <= 10000 is 36 (for 9999)
    int maxSum = 36;
    int* groupSizes = (int*)calloc(maxSum + 1, sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        int sum = digitSum(i);
        groupSizes[sum]++;
    }
    
    int maxSize = 0;
    int count = 0;
    for (int i = 1; i <= maxSum; i++) {
        if (groupSizes[i] > maxSize) {
            maxSize = groupSizes[i];
            count = 1;
        } else if (groupSizes[i] == maxSize) {
            count++;
        }
    }
    
    free(groupSizes);
    return count;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int result = countLargestGroup(n);
    printf("Number of groups with largest size: %d\n", result);
    
    return 0;
}