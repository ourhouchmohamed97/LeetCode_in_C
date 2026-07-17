// Sorted GCD Pair Queries

int compareLongLong(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;

    return (x > y) - (x < y);
}

int lowerBound(long long* arr, int size, long long target) {
    int left = 0;
    int right = size;

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gcdValues(
    int* nums,
    int numsSize,
    long long* queries,
    int queriesSize,
    int* returnSize
) {
    int maxValue = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }
    }

    int* freq = calloc(maxValue + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    long long* count = calloc(maxValue + 1, sizeof(long long));

    for (int gcdValue = maxValue; gcdValue >= 1; gcdValue--) {
        long long total = 0;

        for (
            int multiple = gcdValue;
            multiple <= maxValue;
            multiple += gcdValue
        ) {
            total += freq[multiple];
        }

        long long pairs = total * (total - 1) / 2;

        for (
            int multiple = 2 * gcdValue;
            multiple <= maxValue;
            multiple += gcdValue
        ) {
            pairs -= count[multiple];
        }

        count[gcdValue] = pairs;
    }

    long long* prefix = malloc(maxValue * sizeof(long long));
    int* values = malloc(maxValue * sizeof(int));

    int size = 0;
    long long sum = 0;

    for (int gcdValue = 1; gcdValue <= maxValue; gcdValue++) {
        if (count[gcdValue] > 0) {
            sum += count[gcdValue];
            prefix[size] = sum;
            values[size] = gcdValue;
            size++;
        }
    }

    int* result = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int index = lowerBound(prefix, size, queries[i] + 1);
        result[i] = values[index];
    }

    free(freq);
    free(count);
    free(prefix);
    free(values);

    return result;
}