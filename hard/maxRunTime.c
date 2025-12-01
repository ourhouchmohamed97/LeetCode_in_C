// Maximum Running Time of N Computers

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long totalEnergy = 0;
    for (int i = 0; i < batteriesSize; i++) totalEnergy += batteries[i];

    qsort(batteries, batteriesSize, sizeof(int), cmp);

    for (int i = batteriesSize - 1; i >= 0; i--) {
        if (batteries[i] > totalEnergy / n) {
            totalEnergy -= batteries[i];
            n--;
        } else break;
    }

    return totalEnergy / n;
}
