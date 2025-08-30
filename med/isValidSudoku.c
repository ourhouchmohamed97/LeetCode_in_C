// Valid Sudoku

#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '1';
            int box_index = (i / 3) * 3 + (j / 3);
            
            if (row[i][num] || col[j][num] || box[box_index][num]) {
                return false;
            }
            
            row[i][num] = 1;
            col[j][num] = 1;
            box[box_index][num] = 1;
        }
    }
    return true;
}

int main() {
    // Example 1: Valid Sudoku
    char* board1[9] = {
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
    
    // Example 2: Invalid Sudoku
    char* board2[9] = {
        "83..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    
    int boardColSize = 9;
    
    printf("Example 1: %s\n", isValidSudoku(board1, 9, &boardColSize) ? "true" : "false");
    printf("Example 2: %s\n", isValidSudoku(board2, 9, &boardColSize) ? "true" : "false");
    
    return 0;
}