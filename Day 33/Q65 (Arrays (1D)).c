/*
Search in a sorted array using binary search.
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
    int n, values[1000], target, low = 0, high, found = -1;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array size must be from 1 to 1000.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1 ||
            (i > 0 && values[i] < values[i - 1])) {
            fprintf(stderr, "Expected a sorted array.\n");
            return 1;
        }
    }
    if (scanf("%d", &target) != 1) return 1;
    high = n - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (values[middle] == target) { found = middle; break; }
        if (values[middle] < target) low = middle + 1;
        else high = middle - 1;
    }
    if (found >= 0) printf("Found at index %d\n", found);
    else puts("-1");
    return 0;
}
