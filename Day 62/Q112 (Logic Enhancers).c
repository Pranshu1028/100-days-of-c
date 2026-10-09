/*
Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.
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
    long long running, maximum;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000 ||
        scanf("%d", &value) != 1) return 1;
    running = maximum = value;
    for (int i = 1; i < n; ++i) {
        if (scanf("%d", &value) != 1) return 1;
        running = running > 0 ? running + value : value;
        if (running > maximum) maximum = running;
    }
    printf("%lld\n", maximum);
    return 0;
}
