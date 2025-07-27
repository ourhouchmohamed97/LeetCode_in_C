// Next Permutation

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int pivot = -1;
    // Step 1: Find the pivot
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    
    if (pivot == -1) {
        // The array is in descending order, reverse it
        reverse(nums, 0, numsSize - 1);
        return;
    }
    
    // Step 2: Find the swap candidate
    int candidate = -1;
    for (int i = numsSize - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            candidate = i;
            break;
        }
    }
    
    // Step 3: Swap the pivot and the candidate
    swap(&nums[pivot], &nums[candidate]);
    
    // Step 4: Reverse the suffix
    reverse(nums, pivot + 1, numsSize - 1);
}

int main() {
    // Test case 1
    int nums1[] = {1, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test case 1: [1, 2, 3]\n");
    printf("Expected output: [1, 3, 2]\n");
    nextPermutation(nums1, numsSize1);
    printf("Actual output: [");
    for (int i = 0; i < numsSize1; i++) {
        printf("%d", nums1[i]);
        if (i < numsSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
    
    // Test case 2
    int nums2[] = {3, 2, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test case 2: [3, 2, 1]\n");
    printf("Expected output: [1, 2, 3]\n");
    nextPermutation(nums2, numsSize2);
    printf("Actual output: [");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d", nums2[i]);
        if (i < numsSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
    
    // Test case 3
    int nums3[] = {1, 1, 5};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test case 3: [1, 1, 5]\n");
    printf("Expected output: [1, 5, 1]\n");
    nextPermutation(nums3, numsSize3);
    printf("Actual output: [");
    for (int i = 0; i < numsSize3; i++) {
        printf("%d", nums3[i]);
        if (i < numsSize3 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
    
    return 0;
}