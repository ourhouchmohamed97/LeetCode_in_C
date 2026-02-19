// Count Binary Substrings

#pragma GCC optimize("O3, unroll-loops")
int countBinarySubstrings(char* s) {
    int prev=0, cur=1, cnt=0;
    for (int i=1; s[i]!='\0'; i++){
        if(s[i]==s[i-1]) cur++;
        else{
            cnt+=fmin(cur, prev);
            prev=cur;
            cur=1;
        }
    }
    return cnt+fmin(cur, prev);
}