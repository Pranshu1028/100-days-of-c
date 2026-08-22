/*
Write a program to print the sum of the first n odd numbers.
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
    long long n;
    if (scanf("%lld", &n) != 1 || n < 0 || n > 3037000499LL) {
        fprintf(stderr, "Enter n in the range 0 to 3037000499.\n");
        return 1;
    }
    printf("%lld\n", n * n);
    return 0;
}
