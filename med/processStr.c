#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Helper function to reverse a string in place 
 * between indices 0 and len-1
 */
void reverseString(char* str, int len) {
    int i = 0;
    int j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

char* processStr(char* s) {
    if (s == NULL) {
        return NULL;
    }

    size_t capacity = 16; // Initial buffer size
    size_t len = 0;       // Current length of the result string
    
    // Allocate initial memory
    char* res = (char*)malloc(capacity * sizeof(char));
    if (res == NULL) {
        return NULL; // Memory allocation failed
    }

    // Iterate through the input string
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '*') {
            // Backspace: remove last character
            if (len > 0) {
                len--;
            }
        } 
        else if (ch == '#') {
            // Double the current string (res += res)
            size_t add_len = len;
            
            // Check if we need to expand the buffer
            // We need enough space for existing string + copy + null terminator
            if (len + add_len + 1 > capacity) {
                // Double capacity or grow enough to fit new content
                size_t new_cap = (len + add_len + 1) * 2;
                char* temp = (char*)realloc(res, new_cap);
                if (temp == NULL) {
                    free(res);
                    return NULL; // Memory allocation failed
                }
                res = temp;
                capacity = new_cap;
            }
            
            // Append the string to itself
            // memmove is safe for overlapping memory regions, though here
            // the destination (res + len) is strictly after source (res)
            memmove(res + len, res, add_len);
            len += add_len;
        } 
        else if (ch == '%') {
            // Reverse the string
            reverseString(res, len);
        } 
        else if (ch >= 'a' && ch <= 'z') {
            // Append a valid character
            // Ensure space for char + null terminator
            if (len + 1 >= capacity) {
                capacity *= 2;
                char* temp = (char*)realloc(res, capacity);
                if (temp == NULL) {
                    free(res);
                    return NULL; // Memory allocation failed
                }
                res = temp;
            }
            res[len++] = ch;
        }
    }

    // Null-terminate the result string
    res[len] = '\0';

    return res;
}

/* 
   Example usage (Main function for testing)
*/
int main() {
    // Test case: "ab#c*d"
    // 1. 'a' -> res = "a"
    // 2. 'b' -> res = "ab"
    // 3. '#'  -> res = "abab"
    // 4. 'c' -> res = "ababc"
    // 5. '*'  -> res = "abab"
    // 6. 'd' -> res = "ababd"
    char input[] = "ab#c*d";
    
    char* output = processStr(input);
    
    if (output != NULL) {
        printf("Input: %s\n", input);
        printf("Output: %s\n", output);
        free(output); // Remember to free the memory allocated by processStr
    } else {
        printf("Memory allocation error.\n");
    }

    return 0;
}