//  Check if Strings Can be Made Equal With Operations II

#include <stdbool.h>

#pragma GCC optimize("O3", "unroll-loops")
bool checkStrings(char* s1, char* s2) {
    int freq[52]={0};
    for(int i=0; s1[i]!='\0'; i++){
        const bool iOdd=i&1;
        freq[iOdd*26+s1[i]-'a']++;
        freq[iOdd*26+s2[i]-'a']--;
    }
    for(int i=0; i<52; i++)
        if (freq[i]!=0) return 0;
    return 1;
}