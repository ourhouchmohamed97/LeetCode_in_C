// Maximum Product of Splitted Binary Tree

#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to compute the total sum of the tree
long long totalSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    return root->val + totalSum(root->left) + totalSum(root->right);
}

// Helper function to compute the maximum product during traversal
long long dfs(struct TreeNode* root, long long total, long long* maxProduct) {
    if (root == NULL) return 0;
    long long leftSum = dfs(root->left, total, maxProduct);
    long long rightSum = dfs(root->right, total, maxProduct);
    long long currentSum = root->val + leftSum + rightSum;
    long long product = currentSum * (total - currentSum);
    if (product > *maxProduct) {
        *maxProduct = product;
    }
    return currentSum;
}

int maxProduct(struct TreeNode* root) {
    long long total = totalSum(root);
    long long maxProduct = 0;
    dfs(root, total, &maxProduct);
    return maxProduct % MOD;
}