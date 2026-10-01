/*
Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
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
    unsigned long long n, low = 1, high;
    if (scanf("%llu", &n) != 1 || n == 0 ||
        n > 3037000499ULL) return 1;
    high = n;
    while (low <= high) {
        unsigned long long middle = low + (high - low) / 2;
        unsigned long long left = middle * (middle + 1) / 2;
        unsigned long long count = n - middle + 1;
        unsigned long long endpoints = middle + n;
        if (count % 2 == 0) count /= 2;
        else endpoints /= 2;
        unsigned long long right = count * endpoints;
        if (left == right) {
            printf("%llu\n", middle);
            return 0;
        }
        if (left < right) low = middle + 1;
        else high = middle - 1;
    }
    puts("-1");
    return 0;
}
