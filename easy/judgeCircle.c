// Robot Return to Origin

#include <stdbool.h>

bool judgeCircle(char* moves) {
    int valh = 0;
    int valc = 0;
    int n = strlen(moves);
    for (int i = 0; i < n; i ++) {
        if (moves[i] == 'U')
            valh +=1;
        if (moves[i] == 'D')
            valh -=1;
        if (moves[i] == 'R')
            valc +=1;
        if (moves[i] == 'L')
            valc -=1;
        
    }
    return valh == 0 && valc == 0;
}