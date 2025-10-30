// Minimum Number of Increments on Subarrays to Form a Target Array


int minNumberOperations(int* target, int targetSize) {
    if (targetSize == 0) return 0;

    int operations = target[0];
    for (int i = 1; i < targetSize; i++) {
        if (target[i] > target[i - 1]) {
            operations += target[i] - target[i - 1];
        }
    }
    return operations;
}

int main() {
    int target[] = {1, 2, 3, 2, 1};
    int size = sizeof(target) / sizeof(target[0]);

    int result = minNumberOperations(target, size);
    printf("Minimum number of operations: %d\n", result);

    return 0;
}
