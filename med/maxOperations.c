// Maximum Number of Operations to Move Ones to the End

int maxOperations(char* s) {
    int n = strlen(s);
    int cnt1 = (s[0] == '1') ? 1 : 0;
    int total = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == '1'){
            cnt1++;
        } if (s[i] == '0' && s[i - 1] == '1'){
            total += cnt1;
        }
    }
    return total;
}