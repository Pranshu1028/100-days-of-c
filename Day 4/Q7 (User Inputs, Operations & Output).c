/*
Write a program to swap two numbers without using a third variable.
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
    if (scanf("%lld %lld", &a, &b) != 2) {
        fprintf(stderr, "Expected two integers.\n");
        return 1;
    }
    /* XOR avoids the overflow possible with addition-based swapping. */
    a ^= b;
    b ^= a;
    a ^= b;
    printf("After swap: %lld %lld\n", a, b);
    return 0;
}
