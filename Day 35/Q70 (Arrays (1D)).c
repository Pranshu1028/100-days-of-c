/*
Rotate an array to the right by k positions.
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
    int n, values[1000], k, rotated[1000];
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Array size must be from 1 to 1000.\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) if (scanf("%d", &values[i]) != 1) return 1;
    if (scanf("%d", &k) != 1 || k < 0) {
        fprintf(stderr, "Rotation count must be non-negative.\n");
        return 1;
    }
    k %= n;
    for (int i = 0; i < n; ++i) rotated[(i + k) % n] = values[i];
    for (int i = 0; i < n; ++i) printf("%s%d", i == 0 ? "" : " ", rotated[i]);
    putchar('\n');
    return 0;
}
