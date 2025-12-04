// Count Collisions on a Road

int countCollisions(char* directions) {
    int n = strlen(directions), ans = 0, l = 0, r = n - 1; 
    while(l < n && directions[l] == 'L') l++;
    while(r >= l && directions[r] == 'R') r--;
    for(int i = l ; i <= r; i++) {
        if(directions[i] != 'S') ans++;
    }
    return ans;
}