// The k-th Lexicographical String of All Happy Strings of Length n

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int cnt;
    int tar;
    char* res;
    bool check;
} State;

void backtrack(char* curr, int depth, char last, int n, State* state) {
    if (state -> check) {
        return;
    }

    if (depth == n) {
        state -> cnt++;
        if (state -> cnt == state -> tar) {
            curr[n] = '\0';
            strcpy(state -> res, curr);
            state -> check = true;
        }
        return;
    }

    char options[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        if (options[i] != last) {
            curr[depth] = options[i];
            backtrack(curr, depth + 1, options[i], n, state);
            if (state -> check) {
                return;
            }
        }
    }
}

char* getHappyString(int n, int k) {
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    char* temp_str = (char*)malloc((n + 1) * sizeof(char));
    
    State state;
    state.cnt = 0;
    state.tar = k;
    state.res = ans;
    state.check = false;

    backtrack(temp_str, 0, 'd', n, &state);

    free(temp_str);

    if (state.check) {
        return ans;
    } else {
        free(ans);
        return "";
    }
}