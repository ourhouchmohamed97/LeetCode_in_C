// Check if Strings Can be Made Equal With Operations I

#include <stdbool.h>

int compare_char(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
bool canBeEqual(char* s1, char* s2) {
    char even_s1[2] = {s1[0], s1[2]};
    char even_s2[2] = {s2[0], s2[2]};
    
    char odd_s1[2] = {s1[1], s1[3]};
    char odd_s2[2] = {s2[1], s2[3]};

    qsort(even_s1, 2, sizeof(char), compare_char);
    qsort(even_s2, 2, sizeof(char), compare_char);
    
    qsort(odd_s1, 2, sizeof(char), compare_char);
    qsort(odd_s2, 2, sizeof(char), compare_char);

    if (even_s1[0] == even_s2[0] && even_s1[1] == even_s2[1] &&
        odd_s1[0] == odd_s2[0] && odd_s1[1] == odd_s2[1]) {
        return 1; 
    }
    
    return 0;
}