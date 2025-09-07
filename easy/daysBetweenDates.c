// Number of Days Between Two Dates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else {
        return (year % 400 == 0) ? 1 : 0;
    }
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int totalDays(char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    
    int total = 0;
    for (int y = 0; y < year; y++) {
        total += isLeapYear(y) ? 366 : 365;
    }
    
    for (int m = 1; m < month; m++) {
        total += daysInMonth(m, year);
    }
    
    total += day;
    return total;
}

int daysBetweenDates(char* date1, char* date2) {
    int days1 = totalDays(date1);
    int days2 = totalDays(date2);
    return abs(days1 - days2);
}

int main() {
    char date1[11], date2[11];
    
    printf("Enter first date (YYYY-MM-DD): ");
    scanf("%10s", date1);
    printf("Enter second date (YYYY-MM-DD): ");
    scanf("%10s", date2);
    
    int result = daysBetweenDates(date1, date2);
    printf("Number of days between %s and %s: %d\n", date1, date2, result);
    
    return 0;
}