/*
Write a program to check if a number is an Armstrong number.
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
    unsigned long long value, remaining, total = 0;
    unsigned digits = 0;
    if (scanf("%lld", &input) != 1 || input < 0) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    value = (unsigned long long)input;
    remaining = value;
    do { ++digits; remaining /= 10U; } while (remaining != 0);
    remaining = value;
    do {
        unsigned digit = (unsigned)(remaining % 10U);
        unsigned long long power = 1;
        for (unsigned i = 0; i < digits; ++i) {
            if (digit != 0 && power > ULLONG_MAX / digit) {
                puts("Not Armstrong");
                return 0;
            }
            power *= digit;
        }
        if (total > ULLONG_MAX - power) {
            puts("Not Armstrong");
            return 0;
        }
        total += power;
        remaining /= 10U;
    } while (remaining != 0);
    puts(total == value ? "Armstrong" : "Not Armstrong");
    return 0;
}
