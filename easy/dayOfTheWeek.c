// Day of the Week

#include <stdio.h>
#include <stdlib.h>

char* dayOfTheWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;
    
    int h = (q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;
    
    char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    char* result = malloc(10 * sizeof(char));
    sprintf(result, "%s", days[h]);
    return result;
}

int main() {
    // Example 1
    int day1 = 31, month1 = 8, year1 = 2019;
    char* result1 = dayOfTheWeek(day1, month1, year1);
    printf("Example 1: day = %d, month = %d, year = %d, Output: %s\n", day1, month1, year1, result1);
    free(result1);

    // Example 2
    int day2 = 18, month2 = 7, year2 = 1999;
    char* result2 = dayOfTheWeek(day2, month2, year2);
    printf("Example 2: day = %d, month = %d, year = %d, Output: %s\n", day2, month2, year2, result2);
    free(result2);

    // Example 3
    int day3 = 15, month3 = 8, year3 = 1993;
    char* result3 = dayOfTheWeek(day3, month3, year3);
    printf("Example 3: day = %d, month = %d, year = %d, Output: %s\n", day3, month3, year3, result3);
    free(result3);

    return 0;
}