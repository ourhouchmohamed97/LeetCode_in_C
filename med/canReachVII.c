// Jump Game VII

bool canReach(char* s, int minJump, int maxJump) {
    int len = strlen(s);
    if (s[len - 1] != '0') return false;

    bool canReachPos[100000] = {false};
    canReachPos[0] = true;

    int windowCount = 0;

    for (int i = 1; i < len; i++) {
        if (i >= minJump && canReachPos[i - minJump]) windowCount++;

        if (i > maxJump && canReachPos[i - maxJump - 1]) windowCount--;

        canReachPos[i] = (windowCount > 0) && (s[i] == '0');
    }

    return canReachPos[len - 1];
}
