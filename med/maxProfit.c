// Best Time to Buy and Sell Stock using Strategy

#pragma GCC optimize("O3, unroll-loops")
long long sum[100001]={0};
long long maxProfit(int* prices, int n, int* strategy, int strategySize, int k) {
    const int k2=k/2;
    long long modify=0;
    for(int i=0; i<n; i++){
        const int x=prices[i]; 
        sum[i+1]=sum[i]+strategy[i]*x;
        modify+=(-(i>=k2 & i<k)& x);
    }
    long long profit=fmax(sum[n], modify+sum[n]-sum[k]);

    for(int i=1; i+k<=n; i++){ 
        modify+=prices[i+k-1]-prices[i+k2-1];
        profit=fmax(profit, modify+sum[n]-sum[i+k]+sum[i]);
    }
    return profit;
}