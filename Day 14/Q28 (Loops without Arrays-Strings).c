/*
Write a program to print the product of even numbers from 1 to n.
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
    int n;
    unsigned long long product = 1;
    if (scanf("%d", &n) != 1 || n < 0 || n > 100000) {
        fprintf(stderr, "Enter n from 0 to 100000.\n");
        return 1;
    }
    for (int value = 2; value <= n; value += 2) {
        if (product > ULLONG_MAX / (unsigned)value) {
            fprintf(stderr, "Product is outside the supported range.\n");
            return 1;
        }
        product *= (unsigned)value;
    }
    printf("%llu\n", product);
    return 0;
}
