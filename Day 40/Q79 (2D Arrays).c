/*
Perform diagonal traversal of a matrix.
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
    int rows, cols, matrix[100][100];
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 100 || cols < 1 || cols > 100) return 1;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", &matrix[r][c]) != 1) return 1;
    int first = 1;
    for (int diagonal = 0; diagonal < rows + cols - 1; ++diagonal) {
        int top = diagonal < cols ? 0 : diagonal - cols + 1;
        int bottom = diagonal < rows ? diagonal : rows - 1;
        if (diagonal % 2 == 0) {
            for (int r = bottom; r >= top; --r) {
                int c = diagonal - r;
                printf("%s%d", first ? "" : " ", matrix[r][c]);
                first = 0;
            }
        } else {
            for (int r = top; r <= bottom; ++r) {
                int c = diagonal - r;
                printf("%s%d", first ? "" : " ", matrix[r][c]);
                first = 0;
            }
        }
    }
    putchar('\n');
    return 0;
}
