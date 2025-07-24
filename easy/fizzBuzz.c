// Fizz Buzz

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char **answer = (char **)malloc(n * sizeof(char *));
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            answer[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            answer[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            answer[i - 1] = strdup("Buzz");
        } else {
            // Convert the number to a string
            char *numStr = (char *)malloc(12 * sizeof(char)); // Enough for 32-bit integers
            sprintf(numStr, "%d", i);
            answer[i - 1] = numStr;
        }
    }
    return answer;
}

// Example usage (main function for testing)
int main() {
    int returnSize;
    char **result;
    
    // Example 1
    result = fizzBuzz(3, &returnSize);
    printf("Example 1 Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(", ");
        free(result[i]); // Free each string
    }
    printf("]\n");
    free(result); // Free the array
    
    // Example 2
    result = fizzBuzz(5, &returnSize);
    printf("Example 2 Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(", ");
        free(result[i]);
    }
    printf("]\n");
    free(result);
    
    // Example 3
    result = fizzBuzz(15, &returnSize);
    printf("Example 3 Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i < returnSize - 1) printf(", ");
        free(result[i]);
    }
    printf("]\n");
    free(result);
    
    return 0;
}