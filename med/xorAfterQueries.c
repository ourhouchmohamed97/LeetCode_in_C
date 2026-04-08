// XOR After Range Multiplication Queries I

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int mod = 1000000007;

    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int k = queries[i][2];
        int v = queries[i][3];

        for (int idx = l; idx <= r; idx += k) {
            nums[idx] = (long long)nums[idx] * v % mod;
        }
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }

    return res;
}