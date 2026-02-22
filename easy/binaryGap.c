// Binary Gap

int binaryGap(int n) {
    int maxDist = 0;
    int curr = -1;
    int prev = -1;
    for (int i = 0; i < 32; i++) {
        if (n>>i&1) {
            prev = curr;
            curr = i; 
            if (prev != -1) maxDist = curr - prev > maxDist?curr - prev: maxDist;
        }
    }
    return maxDist;
}