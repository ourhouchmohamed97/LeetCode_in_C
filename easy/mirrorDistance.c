// Mirror Distance of an Integer

#pragma optimize("O3, unroll-loops")
int mirrorDistance(int n) {
    long long rev=0;
    for(int x=n; x; x/=10){
        rev=10*rev+x%10;
    }
    return abs(rev-n);
}