// Find X Value of Array II

class Solution {
public:
    struct Node {
        int prod;
        vector<int> freq;
        Node() : prod(1) {}
        void init(int k) {
            freq.assign(k, 0);
        }
    };
    
    int k;
    vector<Node> tree;
    
    void merge(const Node& L, const Node& R, Node& res) {
        res.prod = (1LL * L.prod * R.prod) % k;
        res.freq = L.freq; 
        for (int r = 0; r < k; ++r) {
            if (R.freq[r]) { 
                int nr = (1LL * L.prod * r) % k;
                res.freq[nr] += R.freq[r];
            }
        }
    }
    
    void build(int v, int tl, int tr, const vector<int>& nums) {
        tree[v].init(k);
        if (tl == tr) {
            tree[v].prod = nums[tl] % k;
            tree[v].freq[tree[v].prod] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, nums);
        build(v * 2 + 1, tm + 1, tr, nums);
        merge(tree[v * 2], tree[v * 2 + 1], tree[v]);
    }
    
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].prod = val % k;
            fill(tree[v].freq.begin(), tree[v].freq.end(), 0); 
            tree[v].freq[tree[v].prod] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos, val);
        else update(v * 2 + 1, tm + 1, tr, pos, val);
        merge(tree[v * 2], tree[v * 2 + 1], tree[v]);
    }
    
    Node query(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        if (r <= tm) return query(v * 2, tl, tm, l, r);
        if (l > tm) return query(v * 2 + 1, tm + 1, tr, l, r);
        Node res;
        res.init(k);
        merge(query(v * 2, tl, tm, l, min(r, tm)), 
              query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r), res);
        return res;
    }
    
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        int n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);
        
        vector<int> ans;
        ans.reserve(queries.size()); 
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.freq[x]);
        }
        return ans;
    }
};