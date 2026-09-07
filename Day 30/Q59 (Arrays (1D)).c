/*
Count even and odd numbers in an array.
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
    int n, value, even = 0, odd = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array size must be from 1 to 1000.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Missing array element.\n");
            return 1;
        }
        if (value % 2 == 0) ++even;
        else ++odd;
    }
    printf("Even=%d, Odd=%d\n", even, odd);
    return 0;
}
