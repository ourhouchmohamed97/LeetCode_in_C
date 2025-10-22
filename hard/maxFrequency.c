// Maximum Frequency of an Element After Performing Operations II

#define N (((int)2e5)+100)
int set[N][2],ori[N][2],temp[N];
int max(int a,int b){
    return ((a>=b)?(a):(b));
}
int min(int a,int b){
    return ((a<=b)?(a):(b));
}

int segtree[(1<<19)];
int _max(int a,int b){
    return ((a>=b)?(a):(b));
}
int _min(int a,int b){
    return ((a<=b)?(a):(b));
}
void segtree_init(int n,int* stsz){
    while((1<<(*stsz))<=n){
        (*stsz)++;
    }
    *stsz = (1<<(*stsz));
    return;
}
void update(int pos,int value,int* stsz){
    int new_pos = pos + (*stsz);
    segtree[new_pos] = value;
    new_pos /= 2;
    while(new_pos>0){
        int leftChildValue = segtree[2*new_pos] , rightChildValue = segtree[2*new_pos+1];
        segtree[new_pos] = _max(leftChildValue,rightChildValue);
        new_pos /= 2;
    }
    return;
}

int query(int start,int end,int* stsz){
    start = start + (*stsz),end=end+(*stsz);
    int ans = 0;
    while(start<=end){
        if(start&1){
            ans = _max(ans,segtree[start++]);
        }   
        if(end%2==0){
            ans = _max(ans,segtree[end--]);
        }
        start/=2;
        end/=2;
    }
    return ans;
}

typedef int compare_self_t(const void* ar,int fr,int sc);
typedef void swap_self_t(const void* ar,int fr,int sc);

int compare_self_int(const void* arr,int f,int s){
    int* a1 =(int*)arr;
    return (a1[f]<a1[s]);
}

void swap_self_int(const void *arr,int f,int s){
    int* a1 =(int*)arr; 
    int t=a1[f];
    a1[f]=a1[s];
    a1[s]=t;
    return;
}
    
void heapify(const void* arr,int root,int sz,compare_self_t compfn,swap_self_t swapfn){
    int greatest = root,left=2*root+1,right=2*root+2;
    if((left<sz)&&(compfn(arr,greatest,left))){
        greatest = left;    
    }
    if((right<sz)&&(compfn(arr,greatest,right))){
        greatest = right;    
    }
    if(greatest!=root){
        swapfn(arr,greatest,root);
        heapify(arr,greatest,sz,compfn,swapfn);
    }
}
void heapSort(const void* arr,int low,int high,compare_self_t compfn,swap_self_t swapfn){
    for(int z=(low+(high-low)/2);z>=low;z--){
        heapify(arr,z,high+1,compfn,swapfn);    
    }
    for(int end=high;end>=low;end--){
        swapfn(arr,low,end);    
        heapify(arr,low,end,compfn,swapfn);    
    }
}
// int set[N][2],ori[N][2],temp[N];
// sorting + co-ordinate compression + binarySearch(lowerBound/upperbound) on top of previous question approach
void coord_compresion(const void* oriN,int* nums,int* sz,int n){
    int z = 0;
    int* ori = ((int*)oriN);
    memset(ori,0,sizeof(ori));
    ori[z*2+0] = nums[0]; // value 
    ori[z*2+1] = 1; // count
    int prev =  nums[0];
    for(int i=1;i<n;i++){
       if(prev!=nums[i]){
           ori[(++z)*2+0] = nums[i];
           ori[z*2+1] = 1;
       }
       else{
          ori[z*2+1]++; 
       }
       prev = nums[i];
    }
    *sz = z+1;
}
int lower_bound_set(const void* _Set,int value,int low,int high){ // give the exact value as these were the one which were set before
    int* _set = (int*)_Set;
    // find value and retunr position
    int ans = low;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(_set[mid*2+0]>value){
            high = mid-1; // new lower high
        }
        else{
            ans = mid; // <= new higher low
            low = mid+1;
        }
    }
    return ans;
}
int lb_set(const void* _Set,int value,int low,int high){ // give the exact value as these were the one which were set before
    int* _set = (int*)_Set;
    // find value and retunr position
    int ans = low;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(_set[mid*2+0]>=value){
            ans = mid; // <= new higher low
            high = mid-1; // new lower high
        }
        else{ // _set[mid*2+0] < value
            low = mid+1;
        }
    }
    return ans;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int ans = 0,i,n=numsSize,op=numOperations,z=0,sz=0,ssz=0,stsz=0;
    heapSort(nums,0,n-1,compare_self_int,swap_self_int);
    coord_compresion(ori,nums,&sz,n);
    memset(temp,0,sizeof(temp));
    memset(segtree,0,sizeof(segtree));
    segtree_init(sz,&stsz);
    for(i=0;i<sz;i++){
        temp[z]=ori[i][0]-k;
        temp[++z]=ori[i][0]+k+1;
        z++;
        ans = max(ans,ori[i][1]);
        update(i,ori[i][1],&stsz);
    }
    heapSort(temp,0,z-1,compare_self_int,swap_self_int);    
    coord_compresion(set,temp,&ssz,z);
    for(i=0;i<ssz;i++){
        set[i][1] = 0;
    }
    for(i=0;i<n;i++){
        int includeStart = nums[i]-k;
        int ExclEndPlus  = nums[i]+k+1;
        int posincludeStart = lower_bound_set(set,includeStart,0,ssz-1);
        int posExclEndPlus = lower_bound_set(set,ExclEndPlus,0,ssz-1);
        set[posincludeStart][1] += 1;
        set[posExclEndPlus][1] -= 1;
    }
    for(int i=0;i<ssz;i++){
        if(i==0) {
           continue;
        }
        set[i][1] += set[i-1][1];
        int fix_high = lower_bound_set(ori,set[i][0]-1,0,sz-1); //<=set[i][0]
        int fix_low  = lb_set(ori,set[i-1][0],0,fix_high);
        if(set[i][1]<=op){
            ans = max(ans,set[i][1]);
        } 
        if(set[i-1][1]<=op){
            ans = max(ans,set[i-1][1]);
        } 
        if((ori[fix_low][0]<=set[i][0])&&(ori[fix_low][0]>=set[i-1][0])){
                int rem = set[i-1][1] - ori[fix_low][1];
                if(rem>=op){
                    ans = max(ans,op+ori[fix_low][1]);
                }
                int same = query(fix_low,fix_high,&stsz);
                rem = set[i-1][1] - same;
                if(rem>op){
                    ans = max(ans,op+same);
                }
                else{
                    ans = max(ans,set[i-1][1]);
                }
        }
    }
    return ans;
}

int main(void) {
    int nums[] = {5, 64};
    int numsLen = sizeof(nums) / sizeof(nums[0]);
    int diff = 42;
    int op = 2;

    int result = maxFrequency(nums, numsLen, diff, op);
    printf("Result: %d\n", result); // Expected output: 2

    // You can test more cases:
    int nums2[] = {1, 2, 4};
    printf("Result: %d\n", maxFrequency(nums2, 3, 2, 5)); // Expected: 3

    int nums3[] = {1, 10, 20, 30};
    printf("Result: %d\n", maxFrequency(nums3, 4, 5, 2)); // Expected: 2

    return 0;
}