// Find All People With Secret

int Find(int* groups, int index) {
    while (index != groups[index]) {
        index = groups[index];
    }
    return index;
}

int cmpfunc(const void *a, const void *b) {
    const int *arr1 = *(const int **)a;
    const int *arr2 = *(const int **)b;
    return arr1[2] - arr2[2];
}

int* findAllPeople(int n, int** meetings, int meetingsSize, int* meetingsColSize, int firstPerson, int* returnSize) {
    int* groups = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
    int result_count = 0;

    for (int k = 0; k < n; k++) {
        groups[k] = k;
    }
    groups[firstPerson] = 0;

    qsort(meetings, meetingsSize, sizeof(meetings[0]), cmpfunc);

    int* temp = (int*)malloc(2 * n * sizeof(int));

    int i = 0;
    while (i < meetingsSize) {
        int currentTime = meetings[i][2];
        int temp_count = 0;
        while (i < meetingsSize && meetings[i][2] == currentTime) {
            int g1 = Find(groups, meetings[i][0]);
            int g2 = Find(groups, meetings[i][1]);
            groups[g1 > g2 ? g1 : g2] = g1 < g2 ? g1 : g2;
            temp[temp_count++] = meetings[i][0];
            temp[temp_count++] = meetings[i][1];
            i++;
        }
        for (int j = 0; j < temp_count; j++) {
            if (Find(groups, temp[j]) != 0) {
                groups[temp[j]] = temp[j];
            }
        }
    }

    for (int j = 0; j < n; j++) {
        if (Find(groups, j) == 0) {
            result[result_count++] = j;
        }
    }

    free(temp);
    free(groups);
    
    *returnSize = result_count;
    return result;
}