/*
Write a program to find and display the sum of the first n natural numbers.
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
    unsigned long long n, first, second;
    if (scanf("%llu", &n) != 1) {
        fprintf(stderr, "Expected a non-negative integer.\n");
        return 1;
    }
    if (n == ULLONG_MAX) {
        fprintf(stderr, "Sum is outside the supported range.\n");
        return 1;
    }
    first = n;
    second = n + 1U;
    if (first % 2U == 0) first /= 2U;
    else second /= 2U;
    if (first != 0 && second > ULLONG_MAX / first) {
        fprintf(stderr, "Sum is outside the supported range.\n");
        return 1;
    }
    printf("Sum=%llu\n", first * second);
    return 0;
}
