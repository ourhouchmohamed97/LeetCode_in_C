// Path Sum II

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int targetSum, int* path, int pathSize, int*** result, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        return;
    }
    
    path[pathSize] = root->val;
    pathSize++;
    
    if (root->left == NULL && root->right == NULL && root->val == targetSum) {
        *result = realloc(*result, (*returnSize + 1) * sizeof(int*));
        (*result)[*returnSize] = malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++) {
            (*result)[*returnSize][i] = path[i];
        }
        *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }
    
    dfs(root->left, targetSum - root->val, path, pathSize, result, returnSize, returnColumnSizes);
    dfs(root->right, targetSum - root->val, path, pathSize, result, returnSize, returnColumnSizes);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int** result = NULL;
    
    if (root == NULL) {
        return result;
    }
    
    int* path = malloc(1000 * sizeof(int));
    dfs(root, targetSum, path, 0, &result, returnSize, returnColumnSizes);
    free(path);
    
    return result;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printPaths(int** paths, int size, int* columnSizes) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", paths[i][j]);
            if (j < columnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void freePaths(int** paths, int size, int* columnSizes) {
    for (int i = 0; i < size; i++) {
        free(paths[i]);
    }
    free(paths);
    free(columnSizes);
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
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(1);

    int targetSum = 22;
    int returnSize;
    int* returnColumnSizes;
    int** result = pathSum(root, targetSum, &returnSize, &returnColumnSizes);
    printPaths(result, returnSize, returnColumnSizes);
    freePaths(result, returnSize, returnColumnSizes);
    freeTree(root);

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    targetSum = 5;
    result = pathSum(root, targetSum, &returnSize, &returnColumnSizes);
    printPaths(result, returnSize, returnColumnSizes);
    freePaths(result, returnSize, returnColumnSizes);
    freeTree(root);

    root = newNode(1);
    root->left = newNode(2);

    targetSum = 0;
    result = pathSum(root, targetSum, &returnSize, &returnColumnSizes);
    printPaths(result, returnSize, returnColumnSizes);
    freePaths(result, returnSize, returnColumnSizes);
    freeTree(root);

    return 0;
}