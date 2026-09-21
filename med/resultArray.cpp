// Find X Value of Array I

 class Solution {
public:
    vector<long long> resultArray(vector<int>& A, int k) {
        vector<long long> res(k, 0);
        vector<long long> freq(k, 0), cur(k, 0);

        for (int a : A) {
            int n = a % k;
            fill(cur.begin(), cur.end(), 0);
            cur[n] = 1;
            for (int x = 0; x < k; x++) {
                if (freq[x]) {
                    cur[(x * n) % k] += freq[x];
                }
            }
            swap(freq, cur);
            for (int x = 0; x < k; x++) {
                res[x] += freq[x];
            }
        }

        return res;
    }
};