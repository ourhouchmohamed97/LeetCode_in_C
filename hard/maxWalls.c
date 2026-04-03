// Maximum Walls Destroyed by Robots

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }

int lowerBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;

    int* left = (int*)calloc(n, sizeof(int));
    int* right = (int*)calloc(n, sizeof(int));
    int* num = (int*)calloc(n, sizeof(int));
    HashItem* robotsToDistance = NULL;
    for (int i = 0; i < n; i++) {
        hashAddItem(&robotsToDistance, robots[i], distance[i]);
    }

    int* sortedRobots = (int*)malloc(n * sizeof(int));
    memcpy(sortedRobots, robots, n * sizeof(int));
    qsort(sortedRobots, n, sizeof(int), cmp);

    int* sortedWalls = (int*)malloc(wallsSize * sizeof(int));
    memcpy(sortedWalls, walls, wallsSize * sizeof(int));
    qsort(sortedWalls, wallsSize, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        int pos1 = upperBound(sortedWalls, wallsSize, sortedRobots[i]);
        int leftPos;
        if (i >= 1) {
            int leftBound =
                max(sortedRobots[i] -
                        hashGetItem(&robotsToDistance, sortedRobots[i], 0),
                    sortedRobots[i - 1] + 1);
            leftPos = lowerBound(sortedWalls, wallsSize, leftBound);
        } else {
            leftPos =
                lowerBound(sortedWalls, wallsSize,
                           sortedRobots[i] - hashGetItem(&robotsToDistance,
                                                         sortedRobots[i], 0));
        }
        left[i] = pos1 - leftPos;

        int rightPos;
        if (i < n - 1) {
            int rightBound =
                min(sortedRobots[i] +
                        hashGetItem(&robotsToDistance, sortedRobots[i], 0),
                    sortedRobots[i + 1] - 1);
            rightPos = upperBound(sortedWalls, wallsSize, rightBound);
        } else {
            rightPos =
                upperBound(sortedWalls, wallsSize,
                           sortedRobots[i] + hashGetItem(&robotsToDistance,
                                                         sortedRobots[i], 0));
        }

        int pos2 = lowerBound(sortedWalls, wallsSize, sortedRobots[i]);
        right[i] = rightPos - pos2;

        if (i == 0) {
            continue;
        }

        int pos3 = lowerBound(sortedWalls, wallsSize, sortedRobots[i - 1]);
        num[i] = pos1 - pos3;
    }

    int subLeft = left[0];
    int subRight = right[0];

    for (int i = 1; i < n; i++) {
        int currentLeft =
            max(subLeft + left[i],
                subRight - right[i - 1] + min(left[i] + right[i - 1], num[i]));
        int currentRight = max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    int result = max(subLeft, subRight);

    free(left);
    free(right);
    free(num);
    free(sortedRobots);
    free(sortedWalls);
    hashFree(&robotsToDistance);

    return result;
}z