// Fancy Sequence

#define MOD 1000000007


typedef struct {
    long long* val;  
    int size;      
    int capacity;   
    long long a, b;  
} Fancy;

long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    x = x % mod;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y / 2;
        x = (x * x) % mod;
    }
    return res;
}

Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));  
    obj->val = (long long*)malloc(100 * sizeof(long long));  
    obj->size = 0;
    obj->capacity = 100; 
    obj->a = 1;
    obj->b = 0;
    return obj;
}

void resizeArray(Fancy* obj) {
    if (obj->size >= obj->capacity) {
        obj->capacity *= 2; 
        obj->val = (long long*)realloc(obj->val, obj->capacity * sizeof(long long));  
    }
}

void fancyAppend(Fancy* obj, int val) {
    resizeArray(obj);  
    long long x = (val - obj->b + MOD) % MOD;
    obj->val[obj->size] = (x * modPow(obj->a, MOD - 2, MOD)) % MOD;  
    obj->size++;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->b = (obj->b + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->a = (obj->a * m) % MOD;
    obj->b = (obj->b * m) % MOD;
}


int fancyGetIndex(Fancy* obj, int idx) {
    if (idx >= obj->size) return -1; 
    return (obj->a * obj->val[idx] + obj->b) % MOD;
}

void fancyFree(Fancy* obj) {
    free(obj->val);  
    free(obj); 
}