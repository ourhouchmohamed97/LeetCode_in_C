// Balanced Binary Tree

#include <stdbool.h>
#include <unistd.h>

/**
 Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool balanced;
int dfs(struct TreeNode* node){
    if (node == NULL)
        return 0;
    int l = dfs(node->left);
    int r = dfs(node->right);
    if (l - r > 1 || r - l > 1)
        balanced = false;
    return (l > r ? l : r) + 1;
}
bool isBalanced(struct TreeNode* root) {
    balanced = true;
    dfs(root);
    return balanced;
}