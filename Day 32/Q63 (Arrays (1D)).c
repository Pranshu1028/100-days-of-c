/*
Merge two arrays.
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
    int n, values[1000], m, second[1000], i = 0, j = 0, first = 1;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000) {
        fprintf(stderr, "First array size must be from 0 to 1000.\n");
        return 1;
    }
    for (i = 0; i < n; ++i) if (scanf("%d", &values[i]) != 1) return 1;
    if (scanf("%d", &m) != 1 || m < 0 || m > 1000 || n + m > 1000) {
        fprintf(stderr, "Invalid second array size.\n");
        return 1;
    }
    for (j = 0; j < m; ++j) if (scanf("%d", &second[j]) != 1) return 1;
    i = 0;
    j = 0;
    while (i < n || j < m) {
        int value = j == m || (i < n && values[i] <= second[j])
                        ? values[i++] : second[j++];
        printf("%s%d", first ? "" : " ", value);
        first = 0;
    }
    putchar('\n');
    return 0;
}
