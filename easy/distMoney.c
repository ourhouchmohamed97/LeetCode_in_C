// Distribute Money to Maximum Children

#include <stdio.h>

int distMoney(int money, int children) {
    if (money < children) return -1;
    money -= children;
    int maxEights = money / 7;
    if (maxEights > children)
        maxEights = children;
    int leftover = money - maxEights * 7;
    if (maxEights == children && leftover > 0)
        maxEights--;
    else if (maxEights == children - 1 && leftover == 3)
        maxEights--;

    return maxEights;
}

int main() {
    printf("%d\n", distMoney(20, 3)); // 1
    printf("%d\n", distMoney(16, 2)); // 2
    printf("%d\n", distMoney(2, 3));  // -1
    printf("%d\n", distMoney(19, 2)); // 1
    printf("%d\n", distMoney(23, 2)); // 1 ✅ fixed
    return 0;
}
