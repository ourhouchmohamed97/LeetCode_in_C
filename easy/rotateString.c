// Rotate String

#include <stdbool.h>
#include <unistd.h>

bool rotateString(char* s, char* goal) {
    int n = strlen(s);
    if (n != strlen(goal)) 
        return false;
    char* doubled = (char*)malloc(2 * n + 1);
    strcpy(doubled, s);
    strcat(doubled, s);
    bool result = strstr(doubled, goal) != NULL;
    free(doubled);

    return result;
}