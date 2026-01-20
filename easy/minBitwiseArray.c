//  Construct the Minimum Bitwise Array I

int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int c = 0;
        int temp = num;
        // Count trailing 1s
        while ((temp & 1) == 1) {
            c++;
            temp >>= 1;
        }
        
        if (c == 0) {
            ans[i] = -1;
        } else {
            // Clear the bit at index (c - 1)
            ans[i] = num & ~(1 << (c - 1));
        }
    }
    
    return ans;
}