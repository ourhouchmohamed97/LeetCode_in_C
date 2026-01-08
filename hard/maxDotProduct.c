// Max Dot Product of Two Subsequences

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Create DP table
    int** dp = (int**)malloc(nums1Size * sizeof(int*));
    for (int i = 0; i < nums1Size; i++) {
        dp[i] = (int*)malloc(nums2Size * sizeof(int));
    }
    
    // Fill DP table
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            int prod = nums1[i] * nums2[j];
            dp[i][j] = prod;
            
            // Option 1: Extend previous subsequence
            if (i > 0 && j > 0) {
                int extend = prod + dp[i-1][j-1];
                if (extend > dp[i][j]) {
                    dp[i][j] = extend;
                }
            }
            
            // Option 2: Skip current element from nums1
            if (i > 0 && dp[i-1][j] > dp[i][j]) {
                dp[i][j] = dp[i-1][j];
            }
            
            // Option 3: Skip current element from nums2
            if (j > 0 && dp[i][j-1] > dp[i][j]) {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    int result = dp[nums1Size-1][nums2Size-1];
    
    // Free memory
    for (int i = 0; i < nums1Size; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
