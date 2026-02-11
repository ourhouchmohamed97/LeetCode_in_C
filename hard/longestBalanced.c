// Longest Balanced Subarray II

typedef struct {
    int mn;
    int mx;
    int lz;
} Node;

static void push(Node* seg, int node) {
    int val = seg[node].lz;
    if (val == 0) 
        return;
    int lc = node << 1;
    int rc = lc | 1;

    seg[lc].mn += val; seg[lc].mx += val; seg[lc].lz += val;
    seg[rc].mn += val; seg[rc].mx += val; seg[rc].lz += val;

    seg[node].lz = 0;
}

static void pull(Node* seg, int node) {
    int lc = node << 1;
    int rc = lc | 1;
    seg[node].mn = (seg[lc].mn < seg[rc].mn) ? seg[lc].mn : seg[rc].mn;
    seg[node].mx = (seg[lc].mx > seg[rc].mx) ? seg[lc].mx : seg[rc].mx;
}

static void update(Node* seg, int node, int segLeft, int segRight, int queryLeft, int queryRight, int addValue) {
    if (queryLeft > queryRight) 
        return;
    if (queryLeft == segLeft && queryRight == segRight) {
        seg[node].mn += addValue;
        seg[node].mx += addValue;
        seg[node].lz += addValue;
        return;
    }

    push(seg, node);
    int mid = (segLeft + segRight) >> 1;

    int leftR = (queryRight < mid) ? queryRight : mid;
    int rightL = (queryLeft > mid + 1) ? queryLeft : (mid + 1);

    update(seg, node << 1, segLeft, mid, queryLeft, leftR, addValue);
    update(seg, node << 1 | 1, mid + 1, segRight, rightL, queryRight, addValue);

    pull(seg, node);
}

static int findFirst(Node* seg, int node, int segLeft, int segRight, int limit) {
    if (segLeft > limit) 
        return -1;
    if (seg[node].mn > 0 || seg[node].mx < 0) 
        return -1;
    if (segLeft == segRight) 
        return segLeft;

    push(seg, node);
    int mid = (segLeft + segRight) >> 1;

    int leftRes = findFirst(seg, node << 1, segLeft, mid, limit);
    if (leftRes != -1) 
        return leftRes;

    if (mid < limit) 
        return findFirst(seg, node << 1 | 1, mid + 1, segRight, limit);
    return -1;
}

int longestBalanced(int* nums, int numsSize) {
    int n = numsSize;
    Node* seg = (Node*)calloc(4 * n + 5, sizeof(Node));

    int* lastPos = (int*)malloc(sizeof(int) * 100005);
    for (int i = 0; i < 100005; i++) 
        lastPos[i] = -1;

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int val = nums[i];
        int prev = lastPos[val];
        int diff = (val & 1) ? -1 : 1;
        update(seg, 1, 0, n - 1, prev + 1, i, diff);
        lastPos[val] = i;
        int start = findFirst(seg, 1, 0, n - 1, i);
        if (start != -1) {
            int len = i - start + 1;
            if (len > maxLen) maxLen = len;
        }
    }

    free(seg);
    free(lastPos);
    return maxLen;
}