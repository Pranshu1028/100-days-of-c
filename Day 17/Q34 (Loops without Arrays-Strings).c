/*
Write a program to check if a number is prime.
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
    long long value;
    if (scanf("%lld", &value) != 1 || value < 0 || value > 1000000000000LL) {
        fprintf(stderr, "Enter an integer from 0 to 1000000000000.\n");
        return 1;
    }
    if (value < 2) {
        puts("Not prime");
        return 0;
    }
    for (long long divisor = 2; divisor <= value / divisor; ++divisor) {
        if (value % divisor == 0) {
            puts("Not prime");
            return 0;
        }
    }
    puts("Prime");
    return 0;
}
