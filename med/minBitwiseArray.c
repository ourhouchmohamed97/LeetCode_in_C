// Construct the Minimum Bitwise Array II

int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        int n = nums[i];
        if(n != 2) ans[i] = n - ((n + 1) & (-n - 1)) / 2;
        else ans[i] = -1;
    }    
    *returnSize = numsSize;
    return ans;
}