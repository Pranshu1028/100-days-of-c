/*
Write a program to find the sum of digits of a number.
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
    unsigned long long magnitude, sum = 0;
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return 1;
    }
    magnitude = value < 0 ? (unsigned long long)(-(value + 1)) + 1U
                          : (unsigned long long)value;
    do {
        sum += magnitude % 10U;
        magnitude /= 10U;
    } while (magnitude != 0);
    printf("%llu\n", sum);
    return 0;
}
