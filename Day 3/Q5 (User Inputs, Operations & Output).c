/*
Write a program to convert temperature from Celsius to Fahrenheit.
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
    double celsius;
    if (scanf("%lf", &celsius) != 1 || !isfinite(celsius)) {
        fprintf(stderr, "Expected a temperature.\n");
        return 1;
    }
    printf("Fahrenheit=%.10g\n", celsius * 9.0 / 5.0 + 32.0);
    return 0;
}
