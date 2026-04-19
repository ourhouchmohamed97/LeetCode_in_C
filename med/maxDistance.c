//  Maximum Distance Between a Pair of Values

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, ans = 0, currDist;

    while (i < nums1Size && j < nums2Size){
        if (nums1[i] > nums2[j]){
            i++;
        } else {
            currDist = j - i;
            ans = ans >= currDist ? ans : currDist;
            j++;
        }
    }
    return ans;
}