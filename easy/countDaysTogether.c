// Count Days Spent Together

#include <stdio.h>
#include <stdlib.h>


int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int convertToDayOfYear(const char* date) {
    int month = (date[0] - '0') * 10 + (date[1] - '0');
    int day = (date[3] - '0') * 10 + (date[4] - '0');
    
    int total = day;
    for (int i = 0; i < month - 1; i++) {
        total += daysInMonth[i];
    }
    return total;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int a1 = convertToDayOfYear(arriveAlice);
    int a2 = convertToDayOfYear(leaveAlice);
    int b1 = convertToDayOfYear(arriveBob);
    int b2 = convertToDayOfYear(leaveBob);
    
    int start = (a1 > b1) ? a1 : b1;
    int end   = (a2 < b2) ? a2 : b2;
    
    if (start > end) return 0;
    return end - start + 1;
}

int main() {
    printf("%d\n", countDaysTogether("08-15", "08-18", "08-16", "08-19")); // Output: 3
    printf("%d\n", countDaysTogether("10-01", "10-31", "11-01", "12-31")); // Output: 0
}
