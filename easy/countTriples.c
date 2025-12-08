// Count Square Sum Triples

#include <stdio.h>
#include <math.h>

int countTriples(int n) {
    int count = 0;
    
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            int cSquared = a * a + b * b;
            int c = (int)sqrt(cSquared);
            
            if (c * c == cSquared && c <= n) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n1 = 5;
    int n2 = 10;
    printf("n = %d -> %d\n", n1, countTriples(n1));  // expect 2
    printf("n = %d -> %d\n", n2, countTriples(n2));  // expect 4
    return 0;
}
