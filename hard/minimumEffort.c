// Minimum Initial Energy to Finish Tasks

int compare(const void* a, const void* b) {
    int* taskA = *(int**)a;
    int* taskB = *(int**)b;
    return (taskA[1] - taskA[0]) - (taskB[1] - taskB[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), compare);
    int ans = 0;
    for (int i = 0; i < tasksSize; i++) {
        int task0 = tasks[i][0];
        int task1 = tasks[i][1];
        if (ans + task0 > task1) {
            ans = ans + task0;
        } else {
            ans = task1;
        }
    }
    return ans;
}