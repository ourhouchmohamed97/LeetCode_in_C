// Check If a String Contains All Binary Codes of Size K

#include <stdbool.h>
#include <stdlib.h>

bool hasAllCodes(char* s, int k) {
    int req = 1 << k;
    int n = strlen(s);
    if (req > n - k + 1)
        return false;
    bool* seen = (bool*) calloc(req, sizeof(bool));
    int mask = req - 1;
    int code = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        code = ((code << 1) & mask) | (s[i] == '1');
        if (i >= k - 1 && !seen[code]) {
            seen[code] = true;
            found++;
            if (found == req) {
                free(seen);
                return true;
            }
        }
    }

    free(seen);
    return false;
}