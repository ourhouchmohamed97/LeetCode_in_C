// Smallest Missing Non-negative Integer After Operations

#include <stdio.h>
#include <stdlib.h>

int findSmallestInteger(int* nums, int numsSize, int value) {
    int* remainderCount = (int*)calloc(value, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int remainder = ((nums[i] % value) + value) % value;
        remainderCount[remainder]++;
    }
    
    int result = 0;
    while (1) {
        int requiredRemainder = result % value;
        
        if (remainderCount[requiredRemainder] == 0) {
            free(remainderCount);
            return result;
        }
        
        remainderCount[requiredRemainder]--;
        result++;
    }
}

int main() {
    int nums1[] = {1, -10, 7, 13, 6, 8};
    int value1 = 5;
    int result1 = findSmallestInteger(nums1, 6, value1);
    printf("Example 1: %d\n", result1);
    
    int nums2[] = {1, -10, 7, 13, 6, 8};
    int value2 = 7;
    int result2 = findSmallestInteger(nums2, 6, value2);
    printf("Example 2: %d\n", result2);
    
    return 0;
}
