// Smallest Subtree with all the Deepest Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Pair {
    int depth;
    struct TreeNode* node;
};

struct Pair dfs(struct TreeNode* root) {
    if (!root) return (struct Pair){0, NULL};
    struct Pair l = dfs(root->left);
    struct Pair r = dfs(root->right);
    if (l.depth > r.depth) return (struct Pair){l.depth + 1, l.node};
    if (r.depth > l.depth) return (struct Pair){r.depth + 1, r.node};
    return (struct Pair){l.depth + 1, root};
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return dfs(root).node;
}