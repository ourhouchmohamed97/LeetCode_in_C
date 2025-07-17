// Same Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* p1 = newNode(1);
    p1->left = newNode(2);
    p1->right = newNode(3);

    struct TreeNode* q1 = newNode(1);
    q1->left = newNode(2);
    q1->right = newNode(3);

    printf("Example 1: %s\n", isSameTree(p1, q1) ? "true" : "false");  // Output: true

    struct TreeNode* p2 = newNode(1);
    p2->left = newNode(2);

    struct TreeNode* q2 = newNode(1);
    q2->right = newNode(2);

    printf("Example 2: %s\n", isSameTree(p2, q2) ? "true" : "false");  // Output: false

    struct TreeNode* p3 = newNode(1);
    p3->left = newNode(2);
    p3->right = newNode(1);
    struct TreeNode* q3 = newNode(1);
    q3->left = newNode(1);
    q3->right = newNode(2);

    printf("Example 3: %s\n", isSameTree(p3, q3) ? "true" : "false");  // Output: false

    freeTree(p1); freeTree(q1);
    freeTree(p2); freeTree(q2);
    freeTree(p3); freeTree(q3);

    return 0;
}