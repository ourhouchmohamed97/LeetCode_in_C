// Kth Smallest Amount With Single Denomination Combination

using ll = long long;

class Solution {
    static constexpr int MAXC = 25;
    vector<ll> dp;

    ll count(ll x, unsigned full) {
        ll cnt = 0;
        for (unsigned m = 1; m <= full; ++m) {
            ll v = dp[m];
            if (v <= x)                       
                cnt += (popcount(m) & 1) ? (x / v) : -(x / v);
        }
        return cnt;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        bitset<MAXC + 1> valid;
        for (int c : coins) {
            valid[c] = 1;
            for (int m = 2 * c; m <= MAXC; m += c) valid[m] = 0;
        }
        coins.clear();
        for (int i = 1; i <= MAXC; ++i)
            if (valid[i]) coins.push_back(i);

        const int sz = static_cast<int>(coins.size());
        if (sz == 1) return static_cast<ll>(coins[0]) * k;

        const unsigned full = (1u << sz) - 1;
        dp.assign(full + 1, -1);

        for (unsigned m = 1; m <= full; ++m) {
            ll lcm = 1;
            for (int i = 0; i < sz; ++i)
                if (m & (1u << i))
                    lcm = lcm / gcd(lcm, coins[i]) * coins[i];
            dp[m] = lcm;
        }

        ll l = 1, r = static_cast<ll>(coins[0]) * k, ans = r;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (count(mid, full) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();