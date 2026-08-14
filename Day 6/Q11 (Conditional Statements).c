/*
Write a program to input an integer and check whether it is even or odd using if–else.
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
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Expected an integer.\n");
        return 1;
    }
    printf("%lld is %s\n", value, value % 2 == 0 ? "even" : "odd");
    return 0;
}
