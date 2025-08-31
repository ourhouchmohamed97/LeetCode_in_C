// Sudoku Solver

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == c) return false;
        // Check column
        if (board[i][col] == c) return false;
        // Check 3x3 box
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == c) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}

void printBoard(char** board, int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the board size
    int boardSize = 9;
    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    // Allocate memory for the board
    char** board = (char**)malloc(boardSize * sizeof(char*));
    for (int i = 0; i < boardSize; i++) {
        board[i] = (char*)malloc(boardSize * sizeof(char));
    }

    // Initialize the board with the example input
    char* initialBoard[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = initialBoard[i][j];
        }
    }

    printf("Original Sudoku board:\n");
    printBoard(board, boardSize);

    // Solve the Sudoku
    solveSudoku(board, boardSize, boardColSize);

    printf("\nSolved Sudoku board:\n");
    printBoard(board, boardSize);

    // Free allocated memory
    for (int i = 0; i < boardSize; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}