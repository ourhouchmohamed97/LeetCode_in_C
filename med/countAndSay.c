// Count and Say

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "1");
        return result;
    }
    
    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* result = (char*)malloc(2 * len * sizeof(char) + 1); // Allocate enough space
    int result_index = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i + 1 < len && prev[i] == prev[i + 1]) {
            count++;
            i++;
        }
        result[result_index++] = count + '0';
        result[result_index++] = prev[i];
    }
    result[result_index] = '\0';
    
    free(prev);
    return result;
}

int main() {
    int n = 4;
    char* result = countAndSay(n);
    printf("countAndSay(%d) = %s\n", n, result);
    free(result);
    
    n = 1;
    result = countAndSay(n);
    printf("countAndSay(%d) = %s\n", n, result);
    free(result);
    
    return 0;
}