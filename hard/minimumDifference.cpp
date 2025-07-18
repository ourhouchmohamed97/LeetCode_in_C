// Minimum Difference in Sums After Removal of Elements

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;
        
        vector<long long> prefixSum(m + 1, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;
        
        for (int i = 1; i <= 2 * n; ++i) {
            int element = nums[i - 1];
            sum += element;
            maxHeap.push(element);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            prefixSum[i] = sum;
        }
        
        vector<long long> suffixSum(m + 2, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        
        for (int i = m; i > n; --i) {
            int element = nums[i - 1];
            sum += element;
            minHeap.push(element);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            suffixSum[i] = sum;
        }
        
        long long ans = LLONG_MAX;
        for (int i = n; i <= 2 * n; ++i) {
            ans = min(ans, prefixSum[i] - suffixSum[i + 1]);
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {3, 1, 2};
    cout << sol.minimumDifference(nums1) << endl; // Output: -1

    vector<int> nums2 = {7, 9, 5, 8, 1, 3};
    cout << sol.minimumDifference(nums2) << endl; // Output: 1

    return 0;
}