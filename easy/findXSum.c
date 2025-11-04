// Find X-Sum of All K-Long Subarrays I

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int num;
    int freq;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *pa = (Pair *)a;
    Pair *pb = (Pair *)b;
    if (pa->freq != pb->freq)
        return pb->freq - pa->freq;
    return pb->num - pa->num;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        Pair freq[1000];
        int freqCount = 0;

        for (int j = i; j < i + k; j++) {
            int found = 0;
            for (int f = 0; f < freqCount; f++) {
                if (freq[f].num == nums[j]) {
                    freq[f].freq++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                freq[freqCount].num = nums[j];
                freq[freqCount].freq = 1;
                freqCount++;
            }
        }
        qsort(freq, freqCount, sizeof(Pair), cmp);
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            for (int f = 0; f < x && f < freqCount; f++) {
                if (nums[j] == freq[f].num) {
                    sum += nums[j];
                    break;
                }
            }
        }

        result[i] = sum;
    }

    return result;
}
