// Construct Uniform Parity Array II

class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int mn = *min_element(a.begin(), a.end());
        if (mn & 1) return true;
        return all_of(a.begin(), a.end(), [](int x) { return (x & 1) == 0; });
    }
};