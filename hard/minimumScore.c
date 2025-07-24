// Minimum Score After Removals on a Tree

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

typedef struct {
    int to;
    int next;
} Edge;

Edge *tree;
int *head;
int edgeCount;
int *xorSubtree;
int *parent;
int *depth;
int n;

void addEdge(int u, int v) {
    tree[edgeCount].to = v;
    tree[edgeCount].next = head[u];
    head[u] = edgeCount++;
    
    tree[edgeCount].to = u;
    tree[edgeCount].next = head[v];
    head[v] = edgeCount++;
}

void dfs(int u, int p, int* nums) {
    xorSubtree[u] = nums[u];
    parent[u] = p;
    depth[u] = (p == -1) ? 0 : depth[p] + 1;
    for (int i = head[u]; i != -1; i = tree[i].next) {
        int v = tree[i].to;
        if (v != p) {
            dfs(v, u, nums);
            xorSubtree[u] ^= xorSubtree[v];
        }
    }
}

int minimumScore(int* nums, int numsSize, int** edges, int edgesSize, int* edgesColSize) {
    n = numsSize;
    if (n == 1) return 0;
    
    // Initialize global variables
    tree = (Edge *)malloc(2 * (n + 1) * sizeof(Edge));
    head = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) head[i] = -1;
    edgeCount = 0;
    
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(u, v);
    }
    
    xorSubtree = (int *)malloc(n * sizeof(int));
    parent = (int *)malloc(n * sizeof(int));
    depth = (int *)malloc(n * sizeof(int));
    
    dfs(0, -1, nums);
    
    int minScore = INT_MAX;
    
    // Iterate all possible pairs of edges
    for (int i = 0; i < edgesSize; i++) {
        int a1 = edges[i][0];
        int b1 = edges[i][1];
        if (depth[a1] < depth[b1]) {
            int temp = a1;
            a1 = b1;
            b1 = temp;
        }
        // Now a1 is the child of b1
        for (int j = i + 1; j < edgesSize; j++) {
            int a2 = edges[j][0];
            int b2 = edges[j][1];
            if (depth[a2] < depth[b2]) {
                int temp = a2;
                a2 = b2;
                b2 = temp;
            }
            // Now a2 is the child of b2
            
            int x, y, z;
            // Check if the second edge is in the subtree of the first edge
            if (depth[a1] >= depth[a2]) {
                int node = a1;
                int isInSubtree = 0;
                while (node != -1 && node != a2) {
                    node = parent[node];
                }
                if (node == a2) {
                    // a1 is in the subtree of a2's parent (b2 is parent of a2)
                    // Split into three parts:
                    // Part 1: subtree of a1
                    x = xorSubtree[a1];
                    // Part 2: subtree of a2 excluding subtree of a1
                    y = xorSubtree[a2] ^ x;
                    // Part 3: total XOR ^ xorSubtree[a2]
                    z = xorSubtree[0] ^ xorSubtree[a2];
                } else {
                    // Independent subtrees
                    x = xorSubtree[a1];
                    y = xorSubtree[a2];
                    z = xorSubtree[0] ^ x ^ y;
                }
            } else {
                int node = a2;
                int isInSubtree = 0;
                while (node != -1 && node != a1) {
                    node = parent[node];
                }
                if (node == a1) {
                    // a2 is in the subtree of a1's parent (b1 is parent of a1)
                    x = xorSubtree[a2];
                    y = xorSubtree[a1] ^ x;
                    z = xorSubtree[0] ^ xorSubtree[a1];
                } else {
                    // Independent subtrees
                    x = xorSubtree[a1];
                    y = xorSubtree[a2];
                    z = xorSubtree[0] ^ x ^ y;
                }
            }
            
            int maxVal = (x > y) ? x : y;
            maxVal = (maxVal > z) ? maxVal : z;
            int minVal = (x < y) ? x : y;
            minVal = (minVal < z) ? minVal : z;
            int score = maxVal - minVal;
            if (score < minScore) {
                minScore = score;
            }
        }
    }
    
    free(tree);
    free(head);
    free(xorSubtree);
    free(parent);
    free(depth);
    
    return minScore;
}

int main() {
    // Example 1
    int nums1[] = {1, 5, 5, 4, 11};
    int* edges1[] = {
        (int[]){0, 1},
        (int[]){1, 2},
        (int[]){1, 3},
        (int[]){3, 4}
    };
    int edgesColSize1 = 2;
    int edgesSize1 = 4;
    int numsSize1 = 5;
    int result1 = minimumScore(nums1, numsSize1, edges1, edgesSize1, &edgesColSize1);
    printf("Example 1 Output: %d\n", result1);  // Expected Output: 9

    // Example 2
    int nums2[] = {5, 5, 2, 4, 4, 2};
    int* edges2[] = {
        (int[]){0, 1},
        (int[]){1, 2},
        (int[]){5, 2},
        (int[]){4, 3},
        (int[]){1, 3}
    };
    int edgesColSize2 = 2;
    int edgesSize2 = 5;
    int numsSize2 = 6;
    int result2 = minimumScore(nums2, numsSize2, edges2, edgesSize2, &edgesColSize2);
    printf("Example 2 Output: %d\n", result2);  // Expected Output: 0

    return 0;
}