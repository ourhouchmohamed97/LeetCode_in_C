// Longest Substring of One Repeating Character

class Solution {
private:
    struct Node {
        char leftChar;
        char rightChar;
        int length;
        int prefix;
        int suffix;
        int best;

        Node() = default;
        Node(char c) : leftChar(c), rightChar(c), length(1), prefix(1), suffix(1), best(1) {}
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        res.prefix = left.prefix;
        if (left.rightChar == right.leftChar && left.prefix == left.length) {
            res.prefix = left.length + right.prefix;
        }

        res.suffix = right.suffix;
        if (left.rightChar == right.leftChar && right.suffix == right.length) {
            res.suffix = right.length + left.suffix;
        }


        res.best = std::max(left.best, right.best);
        if (left.rightChar == right.leftChar) {
            res.best = std::max(res.best, left.suffix + right.prefix);
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);
        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int index, char ch) {
        if (start == end) {
            tree[node] = Node(ch);
            return;
        }

        int mid = start + (end - start) / 2;
        (index <= mid) ? update(node * 2, start, mid, index, ch)
                       : update(node * 2 + 1, mid + 1, end, index, ch);
        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(const string& s, 
                                  const string& queryCharacters, 
                                  const vector<int>& queryIndices) {
        const int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> answer;
        answer.reserve(queryIndices.size());

        for (size_t i = 0; i < queryIndices.size(); ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};