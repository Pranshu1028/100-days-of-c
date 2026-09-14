/*
Find the sum of each row of a matrix and store it in an array.
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
    long long row_sum;
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 100 || cols < 1 || cols > 100) {
        fprintf(stderr, "Invalid matrix dimensions.\n");
        return 1;
    }
    for (int r = 0; r < rows; ++r) {
        row_sum = 0;
        for (int c = 0; c < cols; ++c) {
            if (scanf("%d", &value) != 1) return 1;
            row_sum += value;
        }
        printf("%s%lld", r == 0 ? "" : " ", row_sum);
    }
    putchar('\n');
    return 0;
}
