// Minimum Operations to Convert All Elements to Zero

static int st[100001]={-1}, top=-1;
static int minOperations(int* nums, int n) {
    top=0;
    int op=0;
    for (int i=0; i<n; i++){
        const int x=nums[i];
        while(x<st[top]) top--;
        if (x>st[top]){
            op+=(x>0);
            st[++top]=x;
        }
    }
    return op;
}