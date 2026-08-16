/*
Write a program to input three numbers and find the largest among them using if–else.
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
    long long a, b, c, largest;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) {
        fprintf(stderr, "Expected three integers.\n");
        return 1;
    }
    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    printf("Largest is %lld\n", largest);
    return 0;
}
