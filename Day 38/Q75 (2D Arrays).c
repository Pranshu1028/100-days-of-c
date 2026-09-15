/*
Add two matrices.
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
    int rows, cols, other_rows, other_cols, a[100][100], b[100][100];
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 100 || cols < 1 || cols > 100) return 1;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", &a[r][c]) != 1) return 1;
    if (scanf("%d %d", &other_rows, &other_cols) != 2 ||
        other_rows != rows || other_cols != cols) {
        fprintf(stderr, "Matrices must have identical dimensions.\n");
        return 1;
    }
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", &b[r][c]) != 1) return 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c)
            printf("%s%lld", c == 0 ? "" : " ",
                   (long long)a[r][c] + b[r][c]);
        putchar('\n');
    }
    return 0;
}
