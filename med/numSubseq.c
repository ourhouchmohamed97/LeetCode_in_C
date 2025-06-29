// Number of Subsequences That Satisfy the Given Sum Condition

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int *pow2 = (int *)malloc((numsSize + 1) * sizeof(int));
    pow2[0] = 1;
    for (int i = 1; i <= numsSize; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    
    int left = 0, right = numsSize - 1;
    int res = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int low = nums[i];
        int max_val = target - low;
        if (max_val < low) {
            continue;
        }
        
        int left = i, right = numsSize - 1;
        int best_j = i;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= max_val) {
                best_j = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (best_j >= i) {
            int count = best_j - i;
            res = (res + pow2[count]) % MOD;
        }
    }
    
    free(pow2);
    return res;
}

int main() {
    int nums[] = {3, 5, 6, 7};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = numSubseq(nums, size, target);
    printf("Number of subsequences: %d\n", result);
    
    return 0;
}