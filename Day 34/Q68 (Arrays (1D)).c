/*
Delete an element from an array.
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
    int n, values[1000], position;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array size must be from 1 to 1000.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) if (scanf("%d", &values[i]) != 1) return 1;
    if (scanf("%d", &position) != 1 || position < 0 || position >= n) {
        fprintf(stderr, "Deletion index must be from 0 to n-1.\n");
        return 1;
    }
    for (int i = position; i < n - 1; ++i) values[i] = values[i + 1];
    for (int i = 0; i < n - 1; ++i) printf("%s%d", i == 0 ? "" : " ", values[i]);
    putchar('\n');
    return 0;
}
