// Number of Substrings With Only 1s

#define MOD 1000000007

int numSub(char* s) {
    long long subCount = 0;
    long long oneCount = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0'){
            subCount += (oneCount * (oneCount+1) / 2) % MOD;
            oneCount = 0;
        } else
            oneCount++;
    }
    subCount += (oneCount * (oneCount+1) / 2) % MOD;

    return (int)subCount;
}