// Minimum Deletions to Make String Balanced

int minimumDeletions(char* s) {
    int b_before_a = 0, deletion = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'b') b_before_a += 1;
        else if(b_before_a > 0 ) {
            b_before_a -= 1;
            deletion += 1;
        }
    }   
    return deletion;
}