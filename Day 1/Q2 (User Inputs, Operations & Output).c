/*
Write a program to input two numbers and display their sum, difference, product, and quotient.
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
    double a, b;
    if (scanf("%lf %lf", &a, &b) != 2 ||
        !isfinite(a) || !isfinite(b)) {
        fprintf(stderr, "Expected two numbers.\n");
        return 1;
    }
    printf("Sum=%.10g, Diff=%.10g, Product=%.10g, ",
           a + b, a - b, a * b);
    if (b == 0.0L) {
        printf("Quotient=undefined (division by zero)\n");
    } else {
        printf("Quotient=%.10g\n", a / b);
    }
    return 0;
}
