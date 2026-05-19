// Minimum Common Value

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int s1 = 0;
    int s2 = 0;
    if (nums1[nums1Size - 1] < nums2[0])
        return -1;
    if (nums2[nums2Size - 1] < nums1[0])
        return -1;
    while (s1 < nums1Size && s2 < nums2Size) {
        if (nums1[s1] == nums2[s2])
            return nums1[s1];
        else if (nums1[s1] < nums2[s2])
            s1++;
        else
            s2++;
    }
    return -1;
}