/*
Find the digit that occurs the most times in an integer number.
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
    unsigned long long value, counts[10] = {0};
    int most = 0;
    if (scanf("%lld", &input) != 1 || input < 0) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    value = (unsigned long long)input;
    do {
        ++counts[value % 10U];
        value /= 10U;
    } while (value != 0);
    for (int digit = 1; digit < 10; ++digit) {
        if (counts[digit] > counts[most]) most = digit;
    }
    printf("%d\n", most);
    return 0;
}
