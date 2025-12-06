// Count Partitions With Max-Min Difference at Most K

#pragma GCC optimize("O3, unroll-loops")
static const int mod=1e9+7;
static int qMax[50000], qMin[50000];
static int frontX, backX, frontN, backN;
static int countPartitions(int* nums, int n, int k) {
    //reset monotonic queue
    frontX=frontN=0;
    backX=backN=-1;

    long long cnt=0;
    int* sum=(int*)alloca((n+2)*sizeof(int));
    memset(sum, 0, sizeof(sum));
    sum[1]=1;

    for (int l=0, r=0; r< n; r++) {
        int x=nums[r];

        // max queue
        while (backX>=frontX && qMax[backX]<x) backX--;
        qMax[++backX]=x;

        // min queue
        while (backN>=frontN && qMin[backN]>x) backN--;
        qMin[++backN]=x;

        // shrink window
        while (qMax[frontX]-qMin[frontN]>k) {
            const int y=nums[l];
            frontX+=(qMax[frontX]==y);
            frontN+=(qMin[frontN]==y);
            l++;
        }

        cnt=(mod+sum[r+1]-sum[l])%mod;
        sum[r+2]=(sum[r+1]+cnt)%mod;
    }
    return cnt;
}