/*
Write a program to find profit or loss percentage given cost price and selling price.
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
    double cost, selling;
    if (scanf("%lf %lf", &cost, &selling) != 2 ||
        !isfinite(cost) || !isfinite(selling) || cost <= 0.0 ||
        selling < 0.0) {
        fprintf(stderr, "Cost must be positive and selling price non-negative.\n");
        return 1;
    }
    if (selling > cost) printf("Profit %.2f%%\n", (selling - cost) * 100.0 / cost);
    else if (selling < cost) printf("Loss %.2f%%\n", (cost - selling) * 100.0 / cost);
    else puts("No Profit No Loss");
    return 0;
}
