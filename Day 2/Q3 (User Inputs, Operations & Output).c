/*
Write a program to calculate the area and perimeter of a rectangle given its length and breadth.
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
    double length, breadth;
    if (scanf("%lf %lf", &length, &breadth) != 2 ||
        !isfinite(length) || !isfinite(breadth) ||
        length < 0.0 || breadth < 0.0) {
        fprintf(stderr, "Enter non-negative length and breadth.\n");
        return 1;
    }
    printf("Area=%.10g, Perimeter=%.10g\n",
           length * breadth, 2.0 * (length + breadth));
    return 0;
}
