// Path Sum

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }
    return hasPathSum(root->left, targetSum - root->val) || 
           hasPathSum(root->right, targetSum - root->val);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(1);

    int targetSum = 22;
    bool result = hasPathSum(root, targetSum);
    printf("%s\n", result ? "true" : "false");

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    targetSum = 5;
    result = hasPathSum(root, targetSum);
    printf("%s\n", result ? "true" : "false");

    root = NULL;
    targetSum = 0;
    result = hasPathSum(root, targetSum);
    printf("%s\n", result ? "true" : "false");

    return 0;
}