// Minimum Cost of Buying Candies With Discount

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), cmp);
    int total = 0;
    int take = 0;
    for (int i = costSize - 1; i >= 0; i--) {
        if (take == 2) {
            take = 0;
        } else {
            total += cost[i];
            take++;
        }
    }
    return total;
}