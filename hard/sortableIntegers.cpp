// Sum of Sortable Integers

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        std::vector<int> desc(n, 0);
        for (int i = 1; i < n; ++i)
            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);

        std::vector<int> premax(n), sufmin(n);
        premax[0] = nums[0];
        for (int i = 1; i < n; ++i)
            premax[i] = std::max(premax[i - 1], nums[i]);
        sufmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            sufmin[i] = std::min(sufmin[i + 1], nums[i]);

        std::vector<bool> cut(n, true);
        for (int m = 1; m < n; ++m)
            cut[m] = premax[m - 1] <= sufmin[m];

        auto rotatable = [&](int l, int r) -> bool {
            return desc[r] - desc[l] + (nums[r] > nums[l] ? 1 : 0) <= 1;
        };

        auto sortable = [&](int k) -> bool {
            for (int l = 0; l < n; l += k)
                if (!cut[l] || !rotatable(l, l + k - 1))
                    return false;
            return true;
        };

        int total = 0;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k != 0) continue;
            if (sortable(k)) total += k;
            const int other = n / k;
            if (other != k && sortable(other)) total += other;
        }
        return total;
    }
};
