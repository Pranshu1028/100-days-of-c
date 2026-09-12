/*
Find the second largest element in an array.
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
    int n, values[1000], largest, second = 0, found = 0;
    if (scanf("%d", &n) != 1 || n < 2 || n > 1000) {
        fprintf(stderr, "Array size must be from 2 to 1000.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) return 1;
    }
    largest = values[0];
    for (int i = 1; i < n; ++i) if (values[i] > largest) largest = values[i];
    for (int i = 0; i < n; ++i) {
        if (values[i] < largest && (!found || values[i] > second)) {
            second = values[i];
            found = 1;
        }
    }
    if (!found) {
        fprintf(stderr, "No distinct second-largest element exists.\n");
        return 1;
    }
    printf("%d\n", second);
    return 0;
}
