/*
Write a program to find the LCM of two numbers.
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
    long long a, b;
    unsigned long long x, y, original_x, original_y, remainder, gcd;
    if (scanf("%lld %lld", &a, &b) != 2) {
        fprintf(stderr, "Expected two integers.\n");
        return 1;
    }
    x = a < 0 ? (unsigned long long)(-(a + 1)) + 1U
              : (unsigned long long)a;
    y = b < 0 ? (unsigned long long)(-(b + 1)) + 1U
              : (unsigned long long)b;
    if (x == 0 || y == 0) {
        puts("0");
        return 0;
    }
    original_x = x;
    original_y = y;
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }
    gcd = x;
    if (original_x / gcd > ULLONG_MAX / original_y) {
        fprintf(stderr, "LCM is outside the supported range.\n");
        return 1;
    }
    printf("%llu\n", (original_x / gcd) * original_y);
    return 0;
}
