// Count Special Triplets

#pragma GCC optimize("O3, unroll-loops")
#define M 100001
int freq[M]={0}, prev[M]={0};
static int specialTriplets(int* nums, int n) {
    const int mod=1e9+7;
    memset(freq, 0, sizeof(freq));
    memset(prev, 0, sizeof(prev));
    for(int i=0; i<n; i++) freq[nums[i]]++;
    long long cnt=0;
    prev[nums[0]]++;
    for(int i=1; i<n-1; i++){
        const int x=nums[i], x2=x<<1;
        if (x2<M)
            cnt+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
        prev[x]++;
    }
    return cnt%mod;
}