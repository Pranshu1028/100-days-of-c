/*
Write a program to take a number as input and print its equivalent binary representation.
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
    unsigned long long value;
    char bits[sizeof(value) * CHAR_BIT + 1];
    size_t count = 0;
    if (scanf("%lld", &input) != 1 || input < 0) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    value = (unsigned long long)input;
    do {
        bits[count++] = (char)('0' + value % 2U);
        value /= 2U;
    } while (value != 0);
    while (count > 0) putchar(bits[--count]);
    putchar('\n');
    return 0;
}
