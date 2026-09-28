/*
Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.
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
    int n, values[1000], target, first = -1, last = -1;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1 ||
            (i > 0 && values[i] < values[i - 1])) {
            fprintf(stderr, "Expected a sorted array.\n");
            return 1;
        }
    }
    if (scanf("%d", &target) != 1) return 1;
    int low = 0, high = n;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (values[middle] < target) low = middle + 1;
        else high = middle;
    }
    if (low < n && values[low] == target) {
        first = low;
        low = 0;
        high = n;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (values[middle] <= target) low = middle + 1;
            else high = middle;
        }
        last = low - 1;
    }
    printf("%d,%d\n", first, last);
    return 0;
}
