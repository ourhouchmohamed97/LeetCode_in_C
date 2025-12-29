// Pyramid Transition Matrix

#include <stdbool.h>
#include <string.h>

bool canBuild(char *row, int len, bool can[26][26][26]) {
    if (len == 1) return true;

    char next[10];
    
    bool dfs(int idx) {
        if (idx == len - 1) {
            return canBuild(next, len - 1, can);
        }

        int a = row[idx] - 'A';
        int b = row[idx + 1] - 'A';

        for (int c = 0; c < 26; c++) {
            if (can[a][b][c]) {
                next[idx] = 'A' + c;
                if (dfs(idx + 1)) return true;
            }
        }
        return false;
    }

    return dfs(0);
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    bool can[26][26][26] = {false};

    for (int i = 0; i < allowedSize; i++) {
        int a = allowed[i][0] - 'A';
        int b = allowed[i][1] - 'A';
        int c = allowed[i][2] - 'A';
        can[a][b][c] = true;
    }

    return canBuild(bottom, strlen(bottom), can);
}