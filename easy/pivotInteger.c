// Find the Pivot Integer

#include <stdio.h>
#include <math.h>

int pivotInteger(int n) {
    long total_sum = (long)n * (n + 1) / 2;
    long x = (long) sqrt(total_sum);
    if (x * x == total_sum && x >= 1 && x <= n) {
        return (int)x;
    }
    return -1;
}


int main() {
    // Test cases
    int test_cases[] = {1, 8, 4, 288, 100};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Testing pivotInteger function:\n");
    printf("n\tResult\n");
    printf("--\t------\n");
    
    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        int result = pivotInteger(n);
        printf("%d\t%d\n", n, result);
    }
    
    // Interactive input
    printf("\nEnter a number to find its pivot integer (or -1 to exit): ");
    int input;
    while (scanf("%d", &input) == 1 && input != -1) {
        int result = pivotInteger(input);
        if (result != -1) {
            printf("Pivot integer for %d is %d\n", input, result);
        } else {
            printf("No pivot integer exists for %d\n", input);
        }
        printf("Enter another number (or -1 to exit): ");
    }
    
    return 0;
}