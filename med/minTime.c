// Find the Minimum Amount of Time to Brew Potions

#include <stdio.h>

long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    if (skillSize == 0 || manaSize == 0)
        return 0;

    long long prefix[skillSize];
    long long sum = 0;

    for (int i = 0; i < skillSize; i++) {
        sum += skill[i];
        prefix[i] = sum;
    }

    long long t_prev = 0;

    for (int j = 1; j < manaSize; j++) {
        long long best = -1e18;
        for (int i = 0; i < skillSize; i++) {
            long long left = (long long)mana[j - 1] * prefix[i]
                           - (long long)mana[j] * (i > 0 ? prefix[i - 1] : 0);
            if (left > best)
                best = left;
        }
        t_prev += best;
    }

    long long total = t_prev + (long long)mana[manaSize - 1] * prefix[skillSize - 1];
    return total;
}


int main(void) {
    int skill1[] = {1, 5, 2, 4};
    int mana1[]  = {5, 1, 4, 2};
    printf("Example 1: %lld\n", minTime(skill1, 4, mana1, 4)); // 110

    int skill2[] = {1, 1, 1};
    int mana2[]  = {1, 1, 1};
    printf("Example 2: %lld\n", minTime(skill2, 3, mana2, 3)); // 5

    int skill3[] = {1, 2, 3, 4};
    int mana3[]  = {1, 2};
    printf("Example 3: %lld\n", minTime(skill3, 4, mana3, 2)); // 21

    return 0;
}
