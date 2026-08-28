/*
Write a program to find the product of odd digits of a number.
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
    long long input;
    unsigned long long value, product = 1;
    if (scanf("%lld", &input) != 1 || input < 0) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    value = (unsigned long long)input;
    while (value != 0) {
        unsigned digit = (unsigned)(value % 10U);
        if (digit % 2U != 0) {
            if (product > ULLONG_MAX / digit) {
                fprintf(stderr, "Product is outside the supported range.\n");
                return 1;
            }
            product *= digit;
        }
        value /= 10U;
    }
    printf("%llu\n", product);
    return 0;
}
