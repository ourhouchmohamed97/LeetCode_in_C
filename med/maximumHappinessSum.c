// Maximize Happiness of Selected Children

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // Descending order
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    // Sort in descending order
    qsort(happiness, happinessSize, sizeof(int), compare);
    
    long long res = 0;
    for (int i = 0; i < k; i++) {
        // Each child at position i has waited through i selections
        int contribution = happiness[i] - i;
        if (contribution > 0) {
            res += (long long)contribution;
        }
    }
    return res;
}
