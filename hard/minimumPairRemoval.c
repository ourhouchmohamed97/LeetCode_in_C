// Minimum Pair Removal to Sort Array II



typedef long long ll;

typedef struct {
    ll sum;
    int i;
} HeapItem;

typedef struct {
    HeapItem *a;
    int size;
    int cap;
} MinHeap;

static void heap_init(MinHeap *h, int cap) {
    h->a = (HeapItem*)malloc(sizeof(HeapItem) * cap);
    h->size = 0;
    h->cap = cap;
}

static void heap_free(MinHeap *h) {
    free(h->a);
}

static void heap_push(MinHeap *h, ll sum, int i) {
    int k = h->size++;
    h->a[k].sum = sum;
    h->a[k].i = i;
    while (k > 0) {
        int p = (k - 1) / 2;
        if (h->a[p].sum < h->a[k].sum ||
            (h->a[p].sum == h->a[k].sum && h->a[p].i <= h->a[k].i)) 
                break;
        HeapItem t = h->a[p];
        h->a[p] = h->a[k];
        h->a[k] = t;
        k = p;
    }
}

static HeapItem heap_pop(MinHeap *h) {
    HeapItem res = h->a[0];
    h->a[0] = h->a[--h->size];
    int k = 0;
    while (1) {
        int l = k * 2 + 1, r = k * 2 + 2, s = k;
        if (l < h->size) {
            if (h->a[l].sum < h->a[s].sum ||
                (h->a[l].sum == h->a[s].sum && h->a[l].i < h->a[s].i)) s = l;
        }
        if (r < h->size) {
            if (h->a[r].sum < h->a[s].sum ||
                (h->a[r].sum == h->a[s].sum && h->a[r].i < h->a[s].i)) s = r;
        }
        if (s == k) 
            break;
        HeapItem t = h->a[s];
        h->a[s] = h->a[k];
        h->a[k] = t;
        k = s;
    }
    return res;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 1) 
        return 0;

    ll *a = (ll*)malloc(sizeof(ll) * n);
    for (int i = 0; i < n; i++) 
        a[i] = (ll)nums[i];

    int *left = (int*)malloc(sizeof(int) * n);
    int *right = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        left[i] = i - 1;
        right[i] = (i + 1 < n) ? i + 1 : -1;
    }

    MinHeap heap;
    heap_init(&heap, (n - 1) * 6 + 10);
    for (int i = 0; i < n - 1; i++) {
        heap_push(&heap, a[i] + a[i + 1], i);
    }

    int rest = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) 
            rest++;
    }

    int ans = 0;

    while (rest > 0) {
        HeapItem top = heap_pop(&heap);
        ll v = top.sum;
        int i = top.i;

        int r = right[i];
        if (r == -1) continue;
        if (left[r] != i) continue;
        if (a[i] + a[r] != v) continue;

        int li = left[i];
        int rr = right[r];

        if (li != -1 && right[li] == i && a[li] > a[i]) rest--;
        if (a[i] > a[r]) rest--;
        if (rr != -1 && left[rr] == r && a[r] > a[rr]) rest--;

        a[i] = v;
        right[i] = rr;
        if (rr != -1) 
            left[rr] = i;
        left[r] = -1;
        right[r] = -1;

        if (li != -1 && right[li] == i && a[li] > a[i]) rest++;
        if (rr != -1 && left[rr] == i && a[i] > a[rr]) rest++;

        if (li != -1 && right[li] == i) {
            heap_push(&heap, a[li] + a[i], li);
        }
        if (rr != -1 && left[rr] == i) {
            heap_push(&heap, a[i] + a[rr], i);
        }

        ans++;
    }

    heap_free(&heap);
    free(a);
    free(left);
    free(right);
    return ans;
}