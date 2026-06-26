// Number of ZigZag Arrays II

#pragma GCC optimize("O3,unroll-loops")
const int mod=1e9+7;
static int m, m2;
int* tmp; // Temporary buffer to avoid self-overwriting
static void mult(const int* A, const int* B, int* C) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            long long sum=0;
            for (int k=0; k<m; k++) {
                sum=(sum+1LL*A[i*m+k]*B[k*m+j])%mod;
            }
            tmp[i*m+j]=sum;
        }
    }
    memcpy(C, tmp, m2*sizeof(int));
}

static void mat_pow(const int* M, int n, int* ans) {
    // identity matrix
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) 
            ans[i*m+j]=(i==j);
    }
    int* P=alloca(m2*sizeof(int));
    memcpy(P, M, m2*sizeof(int));

    for (; n>0; n>>=1) {
        if (n&1) mult(ans, P, ans);
        mult(P, P, P);
    }
}

static int zigZagArrays(int n, int l, int r) {
    m=r-l+1;
    m2=m*m;
    tmp=(int*)alloca(m2*sizeof(int));

    int* U=(int*)alloca(m2*sizeof(int));
    int* L=(int*)alloca(m2*sizeof(int));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++) U[i*m+j]=(i<j);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++) L[i*m+j]=(i>j);
    }

    n--; 
    const int n0=n>>1;

    int* UL=(int*)alloca(m2*sizeof(int));
    int* P=(int*)alloca(m2*sizeof(int));

    mult(U, L, UL);    
    mat_pow(UL, n0, P); 
    if (n&1) mult(L, P, P); 

    long long Sum=0;
    for (int i=0; i<m2; i++) 
        Sum+=P[i];
    return Sum*2%mod;
}
