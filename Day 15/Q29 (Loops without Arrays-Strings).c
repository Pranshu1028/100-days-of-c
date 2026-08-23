/*
Write a program to calculate the factorial of a number.
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
    unsigned n;
    unsigned long long factorial = 1;
    if (scanf("%u", &n) != 1 || n > 20U) {
        fprintf(stderr, "Enter n from 0 to 20.\n");
        return 1;
    }
    for (unsigned i = 2; i <= n; ++i) factorial *= i;
    printf("%llu\n", factorial);
    return 0;
}
