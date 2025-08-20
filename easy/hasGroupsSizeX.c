// X of a Kind in a Deck of Cards

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    if (deckSize < 2) return false;
    
    int max_val = 0;
    for (int i = 0; i < deckSize; i++) {
        if (deck[i] > max_val) max_val = deck[i];
    }
    
    int* freq = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < deckSize; i++) {
        freq[deck[i]]++;
    }
    
    int g = 0;
    for (int i = 0; i <= max_val; i++) {
        if (freq[i] > 0) {
            if (g == 0) {
                g = freq[i];
            } else {
                g = gcd(g, freq[i]);
            }
        }
    }
    
    free(freq);
    return g >= 2;
}

int main() {
    int deck1[] = {1,2,3,4,4,3,2,1};
    int size1 = 8;
    printf("%d\n", hasGroupsSizeX(deck1, size1)); // Output: 1 (true)
    
    int deck2[] = {1,1,1,2,2,2,3,3};
    int size2 = 8;
    printf("%d\n", hasGroupsSizeX(deck2, size2)); // Output: 0 (false)
    
    return 0;
}