// Maximum Fruits Harvested After at Most K Steps

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxFruits = 0;
        int currentSum = 0;
        for (int i = 0, j = 0; j < fruits.size(); ++j){
            int positionJ = fruits[j][0];
            int fruitCountJ = fruits[j][1];
            currentSum += fruitCountJ;
            while (i <= j && positionJ - fruits[i][0] + 
                   min(abs(startPos - fruits[i][0]), abs(startPos - positionJ)) > k) {
                currentSum -= fruits[i][1];
                i++; 
            }

            maxFruits = max(maxFruits, currentSum);
        }

        return maxFruits;
    }
}; 

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> fruits1 = {{2, 8}, {6, 3}, {8, 6}};
    int startPos1 = 5;
    int k1 = 4;
    cout << "Test case 1: " << solution.maxTotalFruits(fruits1, startPos1, k1) << endl; // Expected output: 9

    // Test case 2
    vector<vector<int>> fruits2 = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    int startPos2 = 5;
    int k2 = 4;
    cout << "Test case 2: " << solution.maxTotalFruits(fruits2, startPos2, k2) << endl; // Expected output: 14

    // Test case 3
    vector<vector<int>> fruits3 = {{0, 3}, {6, 4}, {8, 5}};
    int startPos3 = 3;
    int k3 = 2;
    cout << "Test case 3: " << solution.maxTotalFruits(fruits3, startPos3, k3) << endl; // Expected output: 0

    return 0;
}