// Apple Redistribution into Boxes

#include <cstdint>

#pragma GCC optimize("O3, unroll-loops")

int minimumBoxes(int* apple, int n, int* capacity, int m) {
    int az=0;
    for(int i=0; i<n; i++) az+=apple[i];
    uint8_t freq[51]={0}, xMax=0;
    for(int i=0; i<m; i++){
        const int x=capacity[i];
        freq[x]++;
        xMax=fmax(x, xMax);
    }
    int cnt=0;
    for(int x=xMax; x>0; x--){
        int f=freq[x];
        if (f==0) continue;
        if (x*f<az){ 
            az-=x*f; 
            cnt+=f; 
        }
        else{
            int q=(az+x-1)/x; // ceil(az/x)
            return cnt+q;
        }
    }
    return -1;
    
}