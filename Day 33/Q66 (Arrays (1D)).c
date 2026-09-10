/*
Insert an element in a sorted array at the appropriate position.
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
    int n, values[1001], value, i, position = 0;
    if (scanf("%d", &n) != 1 || n < 0 || n >= 1000) {
        fprintf(stderr, "Array size must be from 0 to 999.\n");
        return 1;
    }
    for (i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1 ||
            (i > 0 && values[i] < values[i - 1])) {
            fprintf(stderr, "Expected a sorted array.\n");
            return 1;
        }
    }
    if (scanf("%d", &value) != 1) return 1;
    while (position < n && values[position] < value) ++position;
    for (i = n; i > position; --i) values[i] = values[i - 1];
    values[position] = value;
    for (i = 0; i <= n; ++i) printf("%s%d", i == 0 ? "" : " ", values[i]);
    putchar('\n');
    return 0;
}
