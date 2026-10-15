/*
Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number
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
    int n, value;
    long long expected = 0, actual = 0;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000000) return 1;
    expected = (long long)n * (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &value) != 1 || value < 0 || value > n) return 1;
        actual += value;
    }
    printf("%lld\n", expected - actual);
    return 0;
}
