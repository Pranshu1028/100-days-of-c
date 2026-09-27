/*
Change the date format from dd/04/yyyy to dd-Apr-yyyy.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int day, month, year, days_in_month;
    static const char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    char input[64], extra;
    if (fgets(input, sizeof(input), stdin) == NULL ||
        sscanf(input, "%d/%d/%d %c", &day, &month, &year, &extra) != 3 ||
        month < 1 || month > 12 || year < 1) {
        fprintf(stderr, "Expected a valid dd/mm/yyyy date.\n");
        return 1;
    }
    days_in_month = month == 2 ? 28 :
        (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31);
    if (month == 2 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        days_in_month = 29;
    if (day < 1 || day > days_in_month) {
        fprintf(stderr, "Day is invalid for the selected month.\n");
        return 1;
    }
    printf("%02d-%s-%04d\n", day, months[month - 1], year);
    return 0;
}
