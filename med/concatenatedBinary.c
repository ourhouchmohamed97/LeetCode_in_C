// Concatenation of Consecutive Binary Numbers

int concatenatedBinary(int n) {
    int shifter = 1;
    int val = 1;
    long long answer = 0;
    int mod = 1000000007;
    
    for(int a = 1; a <= n; a++){
        if(val * 2 == a){
            shifter++;
            val = a;
        }
        answer = ((answer << shifter) | a) % mod;
    }
    
    return (int) answer;
}