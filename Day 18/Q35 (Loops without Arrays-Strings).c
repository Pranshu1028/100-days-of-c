/*
Write a program to print all factors of a given number.
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
    long long small_factors[31624], large_factors[31624];
    int small_count = 0, large_count = 0;
    if (scanf("%lld", &value) != 1 || value <= 0 || value > 1000000000LL) {
        fprintf(stderr, "Enter a positive integer up to 1000000000.\n");
        return 1;
    }
    for (long long divisor = 1; divisor <= value / divisor; ++divisor) {
        if (value % divisor == 0) {
            small_factors[small_count++] = divisor;
            if (divisor != value / divisor)
                large_factors[large_count++] = value / divisor;
        }
    }
    for (int i = 0; i < small_count; ++i)
        printf("%s%lld", i == 0 ? "" : " ", small_factors[i]);
    for (int i = large_count - 1; i >= 0; --i)
        printf(" %lld", large_factors[i]);
    putchar('\n');
    return 0;
}
