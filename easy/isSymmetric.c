// Symmetric Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    return (left->val == right->val) && 
           isMirror(left->left, right->right) && 
           isMirror(left->right, right->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Example 1: Symmetric tree
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);
    
    printf("Example 1: %s\n", isSymmetric(root1) ? "true" : "false");  // Expected: true

    // Example 2: Asymmetric tree
    //     1
    //    / \
    //   2   2
    //    \   \
    //    3    3
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);
    
    printf("Example 2: %s\n", isSymmetric(root2) ? "true" : "false");  // Expected: false

    // Free allocated memory
    free(root1->left->left);
    free(root1->left->right);
    free(root1->right->left);
    free(root1->right->right);
    free(root1->left);
    free(root1->right);
    free(root1);

    free(root2->left->right);
    free(root2->right->right);
    free(root2->left);
    free(root2->right);
    free(root2);

    return 0;
}