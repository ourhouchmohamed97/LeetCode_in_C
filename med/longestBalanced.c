// Longest Balanced Subarray I

static int cmpInt(const void* a, const void* b){
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int longestBalanced(int* nums, int numsSize) {
    int n = numsSize;
    int res = 0;
    int* vals = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
        vals[i] = nums[i];
    qsort(vals, n, sizeof(int), cmpInt);

    int m = 0;
    for (int i = 0; i < n; i++){
        if (i == 0 || vals[i] != vals[i - 1]) 
            vals[m++] = vals[i];
    }

    int* id = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        int x = nums[i];
        int l = 0, r = m;
        while (l < r){
            int mid = (l + r) >> 1;
            if (vals[mid] < x) 
                l = mid + 1;
            else r = mid;
        }
        id[i] = l; 
    }

    int* seenStamp = (int*)calloc(m, sizeof(int));
    int curStamp = 0;

    for (int i = 0; i < n; i++){
        if (res > n - i) 
            break;
        curStamp++;
        int balance = 0;
        for (int j = i; j < n; j++){
            int idx = id[j];
            if (seenStamp[idx] != curStamp){
                seenStamp[idx] = curStamp;
                balance += (nums[j] % 2 == 0) ? 1 : -1;
            }
            if (balance == 0){
                int len = j - i + 1;
                if (len > res) 
                    res = len;
            }
        }
    }

    free(vals);
    free(id);
    free(seenStamp);
    return res;
}