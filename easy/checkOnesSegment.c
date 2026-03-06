// Check if Binary String Has at Most One Segment of Ones


#include <stdbool.h>

bool checkOnesSegment(char* s) {
    for(int i = 1; s[i]; i++) {
        if(s[i] == '1' && s[i - 1] == '0') return false;
    }
    return true;
}