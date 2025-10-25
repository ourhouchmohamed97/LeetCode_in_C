// Calculate Money in Leetcode Bank

#include <stdio.h>

int totalMoney(int n) {
    int total = 0;
    int weekStart = 1;
    
    for (int i = 0; i < n; i++) {
        total += weekStart + (i % 7);
        
        if ((i + 1) % 7 == 0) {
            weekStart++;
        }
    }
    return total;
}

int main(void) {
    printf("%d\n", totalMoney(4));   // 10
    printf("%d\n", totalMoney(10));  // 37
    printf("%d\n", totalMoney(20));  // 96
    return 0;
}
