/*
Write a program to check if a number is a strong number.
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
    unsigned long long value, remaining, sum = 0;
    static const unsigned long long factorial[] =
        {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    if (scanf("%lld", &input) != 1 || input < 0) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    value = (unsigned long long)input;
    remaining = value;
    do {
        sum += factorial[remaining % 10U];
        remaining /= 10U;
    } while (remaining != 0);
    puts(sum == value ? "Strong number" : "Not strong number");
    return 0;
}
