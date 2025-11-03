// Minimum Time to Make Rope Colorful

int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int totalTime = 0;
    int i = 0;

    while (i < neededTimeSize - 1) {
        if (colors[i] == colors[i + 1]) {
            // Find consecutive group of same colors
            int maxTime = neededTime[i];
            int sumTime = neededTime[i];
            int j = i + 1;

            while (j < neededTimeSize && colors[j] == colors[i]) {
                sumTime += neededTime[j];
                if (neededTime[j] > maxTime)
                    maxTime = neededTime[j];
                j++;
            }

            // Remove all except the one with max time
            totalTime += (sumTime - maxTime);
            i = j; // move to next color group
        } else {
            i++;
        }
    }

    return totalTime;
}
