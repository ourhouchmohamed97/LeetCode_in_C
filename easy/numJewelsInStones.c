// Jewels and Stones

#include <stdio.h>
#include <string.h>

int numJewelsInStones(char* jewels, char* stones) {
    int count = 0;
    for (int i = 0; i < strlen(jewels); i++) {
        for (int j = 0; j < strlen(stones); j++) {
            if (jewels[i] == stones[j])
                count++;
        }
    }
    return count;
}

int main() {
    // Test case 1
    char jewels1[] = "aA";
    char stones1[] = "aAAbbbb";
    printf("Test case 1:\n");
    printf("Jewels: %s, Stones: %s\n", jewels1, stones1);
    printf("Expected output: 3\n");
    printf("Actual output: %d\n\n", numJewelsInStones(jewels1, stones1));

    // Test case 2
    char jewels2[] = "z";
    char stones2[] = "ZZ";
    printf("Test case 2:\n");
    printf("Jewels: %s, Stones: %s\n", jewels2, stones2);
    printf("Expected output: 0\n");
    printf("Actual output: %d\n\n", numJewelsInStones(jewels2, stones2));

    // Test case 3
    char jewels3[] = "abc";
    char stones3[] = "aabbcc";
    printf("Test case 3:\n");
    printf("Jewels: %s, Stones: %s\n", jewels3, stones3);
    printf("Expected output: 6\n");
    printf("Actual output: %d\n\n", numJewelsInStones(jewels3, stones3));

    // Test case 4
    char jewels4[] = "XYZ";
    char stones4[] = "xyzXYZ";
    printf("Test case 4:\n");
    printf("Jewels: %s, Stones: %s\n", jewels4, stones4);
    printf("Expected output: 3\n");
    printf("Actual output: %d\n\n", numJewelsInStones(jewels4, stones4));

    return 0;
}