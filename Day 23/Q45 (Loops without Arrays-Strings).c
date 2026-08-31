/*
Write a program to find the sum of the series: 2/3 + 4/7 + 6/11 + 8/15 + ... up to n terms.
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
    double sum = 0.0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) {
        fprintf(stderr, "Enter a term count from 1 to 1000000.\n");
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        sum += (double)(2 * i) / (4 * i - 1);
    }
    printf("Approximate sum: %.2f\n", sum);
    return 0;
}
