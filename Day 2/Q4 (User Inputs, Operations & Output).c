/*
Write a program to calculate the area and circumference of a circle given its radius.
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
    double radius;
    const double pi = 3.14159265358979323846;
    if (scanf("%lf", &radius) != 1 ||
        !isfinite(radius) || radius < 0.0) {
        fprintf(stderr, "Enter a non-negative radius.\n");
        return 1;
    }
    printf("Area=%.2f, Circumference=%.2f\n",
           pi * radius * radius, 2.0 * pi * radius);
    return 0;
}
