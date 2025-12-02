// Count Number of Trapezoids I

#pragma GCC optimize("O3, unroll-loop")
static inline int cmp(const void * a, const void * b){
   return (*(int*)a-*(int*)b);
}
static int countTrapezoids(int** points, int n, int* pointsColSize) {
    const long long mod=1e9+7;
    int* y=(int*)alloca(n*sizeof(int));
    for(int i=0; i<n; i++) y[i]=points[i][1];
    qsort(y, n, sizeof(int), cmp);
    long long sum=0, c2=0, c=0;
    int f=1, prev=y[0];
    for(int i=1; i<n; i++){
        if (prev==y[i]) f++;
        else{
            c=f*(f-1LL)/2LL;
            sum+=c;
            c2+=c*c;
            f=1;
            prev=y[i];
        }
    }
    c=f*(f-1LL)/2LL;
    sum+=c;
    c2+=c*c;
    return (sum*sum-c2)/2%mod;
}