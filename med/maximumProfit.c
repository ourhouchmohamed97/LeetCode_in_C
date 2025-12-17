// Best Time to Buy and Sell Stock V

#pragma GCC optimize("O3, unroll-loops")
typedef long long ll;
typedef struct{
    ll profit, buy, sell;
} Data;
static inline void ini(Data* X, ll p, ll b, ll s){
    X->profit=p; X->buy=b; X->sell=s;
}
static inline ll max(ll x, ll y){ return x<y?y:x; }
Data dp[501];
static long long maximumProfit(int* prices, int n, int k) {
    const int x0=prices[0];
    for(int t=0; t<=k; t++){
        ini(&dp[t], 0, -x0, x0);
    }
    for(int i=1; i<n; i++){
        const int x=prices[i];
        for(int t=k; t>0; t--){
            Data* cur=&dp[t];
            ll *p=&(cur->profit),*b=&(cur->buy), *s=&(cur->sell);
            const long long prevP=dp[t-1].profit;
            *p=max(*p, max((*b)+x, (*s)-x));
            *b=max(*b, prevP-x);
            *s=max(*s, prevP+x);
        }
    }
    return dp[k].profit;
}
