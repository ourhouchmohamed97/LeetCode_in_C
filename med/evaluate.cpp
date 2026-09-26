// Evaluate the Bracket Pairs of a String

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size());
        for (auto& p : knowledge)
            dict[std::move(p[0])] = std::move(p[1]);

        string res;
        res.reserve(s.size());

        const int n = (int)s.size();
        for (int i = 0; i < n; ) {
            if (s[i] != '(') {
                res.push_back(s[i++]);
                continue;
            }
            size_t j = s.find(')', ++i);
            auto it = dict.find(s.substr(i, j - i));
            res += (it != dict.end()) ? it->second : "?";
            i = j + 1;
        }
        return res;
    }
};