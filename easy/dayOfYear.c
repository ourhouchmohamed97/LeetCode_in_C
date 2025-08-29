// Day of the Year

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else {
        return (year % 400 == 0);
    }
}

int dayOfYear(char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    
    int cumulativeDays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int dayOfYear = cumulativeDays[month - 1] + day;
    
    if (month > 2 && isLeapYear(year)) {
        dayOfYear += 1;
    }
    
    return dayOfYear;
}

int main() {
    char date[11];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", date);
    
    int result = dayOfYear(date);
    printf("Output: %d\n", result);
    
    return 0;
}