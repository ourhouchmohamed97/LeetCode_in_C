// Create Binary Tree From Descriptions

#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* createBinaryTree(
    int** descriptions,
    int descriptionsSize,
    int* descriptionsColSize
) {
    struct TreeNode* nodes[100001] = {0};
    bool children[100001] = {0};
    for (int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        int isLeft = descriptions[i][2];
        if (nodes[parent] == NULL)
            nodes[parent] = createNode(parent);
        if (nodes[child] == NULL)
            nodes[child] = createNode(child);
        children[child] = true;
        if (isLeft)
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    for (int i = 1; i <= 100000; i++) {
        if (nodes[i] != NULL && !children[i])
            return nodes[i];
    }
    return NULL;
}