/*
Write a program to reverse a given number.
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
    unsigned long long magnitude, reversed = 0;
    int negative;
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return 1;
    }
    negative = value < 0;
    magnitude = negative ? (unsigned long long)(-(value + 1)) + 1U
                         : (unsigned long long)value;
    do {
        unsigned digit = (unsigned)(magnitude % 10U);
        if (reversed > (ULLONG_MAX - digit) / 10U) {
            fprintf(stderr, "Reversed value is too large.\n");
            return 1;
        }
        reversed = reversed * 10U + digit;
        magnitude /= 10U;
    } while (magnitude != 0);
    if (negative) putchar('-');
    printf("%llu\n", reversed);
    return 0;
}
