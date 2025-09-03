// Find the Number of Ways to Place People II

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if (p1[0] != p2[0]) return p1[0] - p2[0]; // Sort by x ascending
    return p2[1] - p1[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);
    
    int count = 0;
    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            if (y1 < y2) continue;
            
            int valid = 1;
            for (int k = i + 1; k < pointsSize && points[k][0] <= x2; k++) {
                if (k == j) continue;
                int y = points[k][1];
                if (y >= y2 && y <= y1) {
                    valid = 0;
                    break;
                }
            }
            if (valid) count++;
        }
    }
    return count;
}

int main() {
    // Test cases
    int test_cases = 3; // Number of test cases (based on examples)
    
    // Example 1: [[1,1], [2,2], [3,3]] -> Output: 0
    int points1[3][2] = {{1, 1}, {2, 2}, {3, 3}};
    int* points1_ptr[3];
    for (int i = 0; i < 3; i++) points1_ptr[i] = points1[i];
    int points1ColSize = 2;
    
    // Example 2: [[6,2], [4,4], [2,6]] -> Output: 2
    int points2[3][2] = {{6, 2}, {4, 4}, {2, 6}};
    int* points2_ptr[3];
    for (int i = 0; i < 3; i++) points2_ptr[i] = points2[i];
    int points2ColSize = 2;
    
    // Example 3: [[3,1], [1,3], [1,1]] -> Output: 2
    int points3[3][2] = {{3, 1}, {1, 3}, {1, 1}};
    int* points3_ptr[3];
    for (int i = 0; i < 3; i++) points3_ptr[i] = points3[i];
    int points3ColSize = 2;
    
    // Run test cases
    printf("Example 1: %d\n", numberOfPairs(points1_ptr, 3, &points1ColSize)); // Expected: 0
    printf("Example 2: %d\n", numberOfPairs(points2_ptr, 3, &points2ColSize)); // Expected: 2
    printf("Example 3: %d\n", numberOfPairs(points3_ptr, 3, &points3ColSize)); // Expected: 2
    
    return 0;
}