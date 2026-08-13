/*
Write a program to input time in seconds and convert it to hours:minutes:seconds format.
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
    long long seconds;
    if (scanf("%lld", &seconds) != 1 || seconds < 0) {
        fprintf(stderr, "Expected a non-negative number of seconds.\n");
        return 1;
    }
    printf("%lld:%lld:%lld\n", seconds / 3600,
           seconds % 3600 / 60, seconds % 60);
    return 0;
}
