// Taking Maximum Energy From the Mystic Dungeon

#include <stdio.h>
#include <limits.h>

int maximumEnergy(int* energy, int energySize, int k) {
    int dp[energySize];
    int maxEnergy = INT_MIN;

    for (int i = energySize - 1; i >= 0; i--) {
        if (i + k < energySize)
            dp[i] = energy[i] + dp[i + k];
        else
            dp[i] = energy[i];

        if (dp[i] > maxEnergy)
            maxEnergy = dp[i];
    }

    return maxEnergy;
}

int main() {
    int energy1[] = {5, 2, -10, -5, 1};
    int k1 = 3;
    int n1 = sizeof(energy1) / sizeof(energy1[0]);
    printf("Example 1:\n");
    printf("Maximum Energy: %d\n", maximumEnergy(energy1, n1, k1));  // Expected output: 3

    int energy2[] = {-2, -3, -1};
    int k2 = 2;
    int n2 = sizeof(energy2) / sizeof(energy2[0]);
    printf("\nExample 2:\n");
    printf("Maximum Energy: %d\n", maximumEnergy(energy2, n2, k2));  // Expected output: -1

    return 0;
}
