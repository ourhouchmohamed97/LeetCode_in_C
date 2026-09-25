// Brace Expansion II

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
    unordered_set<string> ans;
    unordered_set<string> visited;

    void dfs(string s){
        if (!visited.insert(s).second) return;

        auto r = s.find('}');

        if (r == string::npos) {
            ans.insert(std::move(s));
            return;
        }

        auto l = s.rfind('{', r);

        size_t start = l + 1;
        while (start <= r) {
            size_t comma = s.find(',', start);
            if (comma > r) comma = r;
            
            string next_s;
            next_s.reserve(l + (comma - start) + (s.size() - r - 1));
            
            next_s.append(s, 0, l);
            next_s.append(s, start, comma - start);
            next_s.append(s, r + 1, s.size() - r - 1);
            
            dfs(std::move(next_s));
            
            start = comma + 1;
        }
    }

    void process(const string& s) {
        int balance = 0;
        size_t start = 0;
        for (size_t i = 0; i <= s.size(); ++i) {
            if (i == s.size() || (s[i] == ',' && balance == 0)) {
                dfs(s.substr(start, i - start));
                start = i + 1;
            } else if (s[i] == '{') {
                balance++;
            } else if (s[i] == '}') {
                balance--;
            }
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        process(expression);
        vector<string> res(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        return res;
    }
};