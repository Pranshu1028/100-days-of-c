/*
Write a program to find the roots of a quadratic equation and categorize them.
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
    double a, b, c, discriminant;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3 ||
        !isfinite(a) || !isfinite(b) || !isfinite(c) || a == 0.0) {
        fprintf(stderr, "Expected coefficients with a non-zero quadratic term.\n");
        return 1;
    }
    discriminant = b * b - 4.0 * a * c;
    if (!isfinite(discriminant)) {
        fprintf(stderr, "Equation coefficients exceed the supported range.\n");
        return 1;
    }
    if (discriminant < 0.0) {
        puts("Roots are complex");
    } else if (discriminant == 0.0) {
        printf("Roots are real and same: %.10g\n", -b / (2.0 * a));
    } else {
        double root = sqrt(discriminant);
        printf("Roots are real and different: %.10g, %.10g\n",
               (-b + root) / (2.0 * a), (-b - root) / (2.0 * a));
    }
    return 0;
}
