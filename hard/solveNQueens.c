// N-Queens

#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int* board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col) return 0;
        if (abs(board[i] - col) == abs(i - row)) return 0;
    }
    return 1;
}

void backtrack(int n, int row, int* board, char**** solutions, int* returnSize, int** returnColumnSizes) {
    if (row == n) {
        char** solution = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            solution[i] = (char*)malloc((n + 1) * sizeof(char));
            for (int j = 0; j < n; j++) {
                if (board[i] == j) {
                    solution[i][j] = 'Q';
                } else {
                    solution[i][j] = '.';
                }
            }
            solution[i][n] = '\0';
        }
        *solutions = (char***)realloc(*solutions, (*returnSize + 1) * sizeof(char**));
        (*solutions)[*returnSize] = solution;
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            backtrack(n, row + 1, board, solutions, returnSize, returnColumnSizes);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    char*** solutions = NULL;
    int* board = (int*)malloc(n * sizeof(int));
    backtrack(n, 0, board, &solutions, returnSize, returnColumnSizes);
    free(board);
    return solutions;
}

int main() {
    int n;
    printf("Enter the size of the chessboard (n): ");
    scanf("%d", &n);

    int returnSize;
    int* returnColumnSizes = NULL;
    char*** solutions = solveNQueens(n, &returnSize, &returnColumnSizes);

    printf("Number of solutions: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("Solution %d:\n", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s\n", solutions[i][j]);
            free(solutions[i][j]);
        }
        free(solutions[i]);
    }
    free(solutions);
    free(returnColumnSizes);

    return 0;
}