// Set Intersection Size At Least Two

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    if(x[1] == y[1]) return y[0] - x[0];
    return x[1] - y[1];
}
int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals,intervalsSize,sizeof(int*),compare);
    int ans = 0, a = -1, b = -1;
    for(int i = 0; i < intervalsSize; i++) {
        int l = intervals[i][0];
        int r = intervals[i][1];
        if(l > b) {
           a = r - 1;
           b = r;
           ans += 2; 
        } else if(l > a) {
            a = b;
            b = r;
            ans += 1;
        }
    }
    return ans;
}