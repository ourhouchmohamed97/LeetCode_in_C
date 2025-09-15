#include <stdio.h>

int squareIsWhite(char* coordinates) {
    int col = coordinates[0] - 'a' + 1;
    int row = coordinates[1] - '0';
    return (col + row) % 2 == 1;
}

int main() {
    printf("%d\n", squareIsWhite("a1")); // 0 (false, black)
    printf("%d\n", squareIsWhite("h3")); // 1 (true, white)
    printf("%d\n", squareIsWhite("c7")); // 0 (false, black)
}
