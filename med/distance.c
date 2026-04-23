// Sum of Distances


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef long long ll;

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void* a, const void* b) {
    Pair* x = (Pair*)a;
    Pair* y = (Pair*)b;
    if (x->val != y->val) 
        return x->val - y->val;
    return x->idx - y->idx;
}

long long* distance(int* nums, int numsSize, int* returnSize) {
    Pair* arr = malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmp);
    ll* res = calloc(numsSize, sizeof(ll));
    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j < numsSize && arr[j].val == arr[i].val) 
            j++;
        int c = j - i;
        if (c > 1) {
            ll sum = 0;
            for (int k = i; k < j; k++)
                sum += arr[k].idx;
            int prev = arr[i].idx;
            res[prev] = sum - (ll)c * prev;
            int left = 0, right = c - 2;
            for (int k = i + 1; k < j; k++) {
                int cur = arr[k].idx;
                res[cur] = res[prev] + (ll)(left - right) * (cur - prev);
                left++;
                right--;
                prev = cur;
            }
        }
        i = j;
    }
    free(arr);
    *returnSize = numsSize;
    return res;
}