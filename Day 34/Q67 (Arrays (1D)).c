/*
Insert an element in an array at a given position.
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
    int n, values[1001], position, value;
    if (scanf("%d", &n) != 1 || n < 0 || n >= 1000) {
        fprintf(stderr, "Array size must be from 0 to 999.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) return 1;
    }
    if (scanf("%d %d", &position, &value) != 2 ||
        position < 0 || position > n) {
        fprintf(stderr, "Position must be from 0 to n.\n");
        return 1;
    }
    for (int i = n; i > position; --i) values[i] = values[i - 1];
    values[position] = value;
    for (int i = 0; i <= n; ++i) printf("%s%d", i == 0 ? "" : " ", values[i]);
    putchar('\n');
    return 0;
}
