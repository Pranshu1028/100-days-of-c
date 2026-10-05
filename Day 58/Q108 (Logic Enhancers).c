/*
Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
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
    int n, values[1000];
    long long prefix[1000], suffix = 1;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    for (int i = 0; i < n; ++i) if (scanf("%d", &values[i]) != 1) return 1;
    long long product = 1;
    for (int i = 0; i < n; ++i) {
        prefix[i] = product;
        if (i + 1 < n) product *= values[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        prefix[i] *= suffix;
        if (i > 0) suffix *= values[i];
    }
    putchar('[');
    for (int i = 0; i < n; ++i)
        printf("%s%lld", i == 0 ? "" : ",", prefix[i]);
    puts("]");
    return 0;
}
