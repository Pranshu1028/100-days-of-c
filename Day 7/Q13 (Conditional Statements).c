/*
Write a program to input a year and check whether it is a leap year or not using conditional statements.
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
    long long year;
    if (scanf("%lld", &year) != 1 || year < 1) {
        fprintf(stderr, "Enter a positive year.\n");
        return 1;
    }
    puts(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
             ? "Leap year" : "Not a leap year");
    return 0;
}
