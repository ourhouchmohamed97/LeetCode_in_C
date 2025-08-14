// Evaluate Reverse Polish Notation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isOperator(const char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0);
}

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < tokensSize; i++) {
        if (!isOperator(tokens[i])) {
            stack[++top] = atoi(tokens[i]);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int result;
            switch (tokens[i][0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }
            stack[++top] = result;
        }
    }
    
    int result = stack[top];
    free(stack);
    return result;
}

int main() {
    // Example 1
    char* tokens1[] = {"2", "1", "+", "3", "*"};
    int tokensSize1 = sizeof(tokens1) / sizeof(tokens1[0]);
    printf("Example 1:\n");
    printf("Input: [\"2\",\"1\",\"+\",\"3\",\"*\"]\n");
    printf("Output: %d\n", evalRPN(tokens1, tokensSize1));

    // Example 2
    char* tokens2[] = {"4", "13", "5", "/", "+"};
    int tokensSize2 = sizeof(tokens2) / sizeof(tokens2[0]);
    printf("\nExample 2:\n");
    printf("Input: [\"4\",\"13\",\"5\",\"/\",\"+\"]\n");
    printf("Output: %d\n", evalRPN(tokens2, tokensSize2));

    // Example 3
    char* tokens3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int tokensSize3 = sizeof(tokens3) / sizeof(tokens3[0]);
    printf("\nExample 3:\n");
    printf("Input: [\"10\",\"6\",\"9\",\"3\",\"+\",\"-11\",\"*\",\"/\",\"*\",\"17\",\"+\",\"5\",\"+\"]\n");
    printf("Output: %d\n", evalRPN(tokens3, tokensSize3));

    return 0;
}