/*
Write a program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.
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
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3 ||
        a <= 0 || b <= 0 || c <= 0 ||
        a > LLONG_MAX - b || a + b <= c ||
        a > LLONG_MAX - c || a + c <= b ||
        b > LLONG_MAX - c || b + c <= a) {
        fprintf(stderr, "Enter positive side lengths forming a triangle.\n");
        return 1;
    }
    if (a == b && b == c) puts("Equilateral");
    else if (a == b || b == c || a == c) puts("Isosceles");
    else puts("Scalene");
    return 0;
}
