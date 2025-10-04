// Container with most water

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    
    while (left < right) {
        int current_height;
        if (height[left] < height[right]) {
            current_height = height[left];
        } else {
            current_height = height[right];
        }
        int current_width = right - left;
        int current_area = current_height * current_width;
        if (current_area > max_area) {
            max_area = current_area;
        }
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

int main() {
    int height1[] = {1,8,6,2,5,4,8,3,7};
    int size1 = sizeof(height1) / sizeof(height1[0]);
    printf("Max area: %d\n", maxArea(height1, size1)); // Output: 49
    
    int height2[] = {1,1};
    int size2 = sizeof(height2) / sizeof(height2[0]);
    printf("Max area: %d\n", maxArea(height2, size2)); // Output: 1
    
    return 0;
}