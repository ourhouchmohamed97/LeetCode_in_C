// Fruits Into Baskets III

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
    vector<int> segTree;

    void buildSegTreeRMQ(vector<int>& baskets, int low, int high, int st_idx) {
        if (low == high) {
            segTree[st_idx] = baskets[low];
            return;
        }

        int mid = low + (high - low) / 2;
        buildSegTreeRMQ(baskets, low, mid, 2 * st_idx);
        buildSegTreeRMQ(baskets, mid + 1, high, 2 * st_idx + 1);
        segTree[st_idx] = max(segTree[2 * st_idx], segTree[2 * st_idx + 1]);
    }

    int findLeftmostBasket(int fruit, int low, int high, int st_idx) {
        if (segTree[st_idx] < fruit)
            return -1;
        if (low == high) {
            segTree[st_idx] = -1;
            return 1; // 1 shows the basket was found
        }

        int mid = low + (high - low) / 2;
        int left = 2 * st_idx;
        int right = 2 * st_idx + 1;

        int result = -1;
        if (segTree[left] >= fruit) {
            result = findLeftmostBasket(fruit, low, mid, left);
        }
        if (result == -1 && segTree[right] >= fruit) {
            result = findLeftmostBasket(fruit, mid + 1, high, right);
        }
        segTree[st_idx] = max(segTree[left], segTree[right]);
        return result;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        segTree = vector<int>(4 * n + 1, -1);

        // Step-1: Build Segment Tree RMQ
        buildSegTreeRMQ(baskets, 0, n - 1, 1);

        // Step-2: Query the leftmost basket to be used
        int count = 0;
        for (int fruit : fruits) {
            if (findLeftmostBasket(fruit, 0, n - 1, 1) == -1)
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> fruits1 = {4, 2, 5};
    vector<int> baskets1 = {3, 5, 4};
    cout << "Test Case 1: " << sol.numOfUnplacedFruits(fruits1, baskets1) << endl; // Expected: 1

    vector<int> fruits2 = {3, 6, 1};
    vector<int> baskets2 = {6, 4, 7};
    cout << "Test Case 2: " << sol.numOfUnplacedFruits(fruits2, baskets2) << endl; // Expected: 0

    vector<int> fruits3 = {1, 2, 3};
    vector<int> baskets3 = {3, 2, 1};
    cout << "Test Case 3: " << sol.numOfUnplacedFruits(fruits3, baskets3) << endl; // Expected: 0

    vector<int> fruits4 = {5, 5, 5};
    vector<int> baskets4 = {4, 4, 4};
    cout << "Test Case 4: " << sol.numOfUnplacedFruits(fruits4, baskets4) << endl; // Expected: 3

    return 0;
}