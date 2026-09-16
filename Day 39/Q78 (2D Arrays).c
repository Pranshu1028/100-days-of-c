/*
Find the sum of main diagonal elements for a square matrix.
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
    int rows, cols, value;
    long long sum = 0;
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 100 || cols != rows) {
        fprintf(stderr, "Enter a square matrix with dimensions from 1 to 100.\n");
        return 1;
    }
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c) {
            if (scanf("%d", &value) != 1) return 1;
            if (r == c) sum += value;
        }
    printf("%lld\n", sum);
    return 0;
}
