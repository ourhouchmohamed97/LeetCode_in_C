// Count Elements With Maximum Frequency

#include <stdio.h>
#include <stdlib.h>

int maxFrequencyElements(int* nums, int numsSize) {
    int freq[101] = {0}; 
    
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 101; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int result = 0;
    for (int i = 0; i < 101; i++) {
        if (freq[i] == maxFreq) {
            result += freq[i];
        }
    }

    return result;
}

int main() {
    int nums1[] = {1, 2, 2, 3, 1, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%d\n", maxFrequencyElements(nums1, size1)); // Output: 4

    int nums2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d\n", maxFrequencyElements(nums2, size2)); // Output: 5

    return 0;
}
