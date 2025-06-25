// Kth Smallest Product of Two Sorted Arrays


#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

long long countLessOrEqual(int* nums1, int nums1Size, int* nums2, int nums2Size, long long mid) {
    long long count = 0;
    for (int i = 0; i < nums1Size; ++i) {
        long long num = nums1[i];
        int left = 0, right = nums2Size - 1;
        long long currentCount = 0;
        if (num > 0) {
            while (left <= right) {
                int m = left + (right - left) / 2;
                if (num * nums2[m] <= mid) {
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            }
            currentCount = left;
        } else if (num < 0) {
            while (left <= right) {
                int m = left + (right - left) / 2;
                if (num * nums2[m] <= mid) {
                    right = m - 1;
                } else {
                    left = m + 1;
                }
            }
            currentCount = nums2Size - left;
        } else {
            if (mid >= 0) {
                currentCount = nums2Size;
            } else {
                currentCount = 0;
            }
        }
        count += currentCount;
    }
    return count;
}

long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2, int nums2Size, long long k) {
    long long left = -1e11, right = 1e11;
    long long result = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long cnt = countLessOrEqual(nums1, nums1Size, nums2, nums2Size, mid);
        if (cnt >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int nums1[] = {-4, -2, 0, 3};
    int nums2[] = {2, 4};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    long long k = 6;

    long long result = kthSmallestProduct(nums1, nums1Size, nums2, nums2Size, k);
    printf("The %lld-th smallest product is: %lld\n", k, result);
    
    return 0;
}