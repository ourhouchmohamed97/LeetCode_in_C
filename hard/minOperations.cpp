// Minimum Operations to Make Elements Within K Subarrays Equal

class Window {
    multiset<int> s;
    multiset<int>::iterator mid;
    long long low, total;
    int odd;

public:
    Window(vector<int>::const_iterator first, vector<int>::const_iterator last)
        : s(first, last), odd(s.size() & 1) {
        mid = next(s.begin(), s.size() / 2);
        low = accumulate(s.begin(), mid, 0LL);
        total = low + accumulate(mid, s.end(), 0LL);
    }

    long long cost() const {
        return total - 2 * low - odd * *mid;
    }

    long long slide(int out, int in) {
        if (out == in) return cost();
        s.insert(in);
        if (in < *mid) low += in - *--mid;
        if (out < *mid) {
            low += *mid++ - out;
            s.erase(s.find(out));
        } else if (out == *mid) {
            mid = s.erase(mid);
        } else {
            s.erase(s.find(out));
        }
        total += in - out;
        return cost();
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        if ((long long)k * x > n) return -1;

        int w = n - x + 1;
        Window win(nums.begin(), nums.begin() + x);
        vector<long long> cost(w);
        cost[0] = win.cost();
        for (int i = 1; i < w; ++i)
            cost[i] = win.slide(nums[i - 1], nums[i + x - 1]);

        const long long INF = LLONG_MAX / 2;
        vector<long long> best(n + 1, 0), layer(n + 1, INF);
        for (int j = 1; j <= k; ++j) {
            fill(layer.begin(), layer.end(), INF);
            int lo = j * x, hi = n - (k - j) * x;
            for (int i = lo; i <= hi; ++i)
                layer[i] = min(layer[i - 1], best[i - x] + cost[i - x]);
            swap(best, layer);
        }
        return best[n];
    }
};