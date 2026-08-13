/*
Write a program to calculate simple and compound interest for given principal, rate, and time.
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
    double principal, rate, time, compound;
    if (scanf("%lf %lf %lf", &principal, &rate, &time) != 3 ||
        !isfinite(principal) || !isfinite(rate) || !isfinite(time) ||
        principal < 0.0 || rate < 0.0 || time < 0.0) {
        fprintf(stderr, "Enter non-negative principal, rate, and time.\n");
        return 1;
    }
    compound = principal * pow(1.0 + rate / 100.0, time) - principal;
    if (!isfinite(compound)) {
        fprintf(stderr, "Interest is outside the supported range.\n");
        return 1;
    }
    printf("Simple Interest=%.2f, Compound Interest=%.2f\n",
           principal * rate * time / 100.0, compound);
    return 0;
}
