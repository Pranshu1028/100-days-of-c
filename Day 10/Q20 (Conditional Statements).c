/*
Write a program to display the day of the week based on a number (1–7) using switch-case.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

static int c11_scanf(const char *format, ...)
    __attribute__((format(gnu_scanf, 1, 2)));

static int c11_scanf(const char *format, ...) {
    va_list arguments;
    int result;
    va_start(arguments, format);
    result = vscanf(format, arguments);
    va_end(arguments);
    return result;
}

#define scanf c11_scanf

int main(void) {
    int day;
    static const char *names[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };
    if (scanf("%d", &day) != 1 || day < 1 || day > 7) {
        fprintf(stderr, "Day number must be from 1 to 7.\n");
        return 1;
    }
    puts(names[day - 1]);
    return 0;
}
