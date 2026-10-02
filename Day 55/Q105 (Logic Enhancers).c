/*
Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
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
    int n, values[1000], candidate = 0, balance = 0, occurrences = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) return 1;
        if (balance == 0) candidate = values[i];
        balance += values[i] == candidate ? 1 : -1;
    }
    for (int i = 0; i < n; ++i) if (values[i] == candidate) ++occurrences;
    printf("%d\n", occurrences > n / 2 ? candidate : -1);
    return 0;
}
