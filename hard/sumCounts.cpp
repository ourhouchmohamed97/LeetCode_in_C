// Subarrays Distinct Element Sum of Squares II

#include <vector>
#include <algorithm>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        std::vector<int> a = nums;
        std::sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());
        for (int& x : nums) {
            x = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        }
        
        const long long MOD = 1e9 + 7;
        std::vector<int> last(a.size(), -1);
        
        struct Node {
            long long c = 0;
            long long s = 0;
        };
        std::vector<Node> tree(n + 2);
        
        long long ans = 0;
        
        for (int r = 0; r < n; r++) {
            int p = last[nums[r]];
            long long c = 0, s = 0;
        
            for (int i = n - p - 1; i > 0; i -= i & -i) {
                c += tree[i].c;
                s += tree[i].s;
            }
            
            long long gain = (long long)(r - p) * (r - p) - 2 * (s - (long long)p * c);

            ans = (ans + (long long)(n - r) * (gain % MOD) % MOD + MOD) % MOD;

            for (int i = n - p; i <= n; i += i & -i) {
                tree[i].c++;
                tree[i].s += p;
            }
            
            last[nums[r]] = r;
        }
        
        return ans;
    }
};