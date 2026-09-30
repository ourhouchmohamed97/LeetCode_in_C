// Maximum Nesting Depth of Two Valid Parentheses Strings

#include <ranges>
class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        namespace rv = std::views;
        auto labels = rv::iota(0, static_cast<int>(s.size()))
                    | rv::transform([&](int i) { return (i ^ s[i]) & 1; });
        return {labels.begin(), labels.end()};
    }
};