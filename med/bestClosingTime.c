// Minimum Penalty for a Shop

int bestClosingTime(char* customers) {
    int penalty = 0;
    int n = 0;

    // Count total 'Y' to initialize penalty for closing at hour 0
    for (int i = 0; customers[i] != '\0'; i++) {
        if (customers[i] == 'Y') {
            penalty++;
        }
        n++;
    }

    int minPenalty = penalty;
    int bestHour = 0;

    // Try closing at hours 1 through n
    for (int i = 0; i < n; i++) {
        if (customers[i] == 'Y') {
            penalty--;  // shop stays open for a customer hour
        } else {
            penalty++;  // shop stays open with no customers
        }

        if (penalty < minPenalty) {
            minPenalty = penalty;
            bestHour = i + 1;
        }
    }

    return bestHour;
}
