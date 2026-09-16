/*
Check if the elements on the diagonal of a matrix are distinct.
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
    int rows, cols, matrix[100][100], distinct = 1;
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 100 || cols < 1 || cols > 100 ||
        rows != cols) {
        fprintf(stderr, "A main diagonal requires a square matrix.\n");
        return 1;
    }
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", &matrix[r][c]) != 1) return 1;
    for (int i = 0; i < rows; ++i)
        for (int j = i + 1; j < rows; ++j)
            if (matrix[i][i] == matrix[j][j]) distinct = 0;
    puts(distinct ? "True" : "False");
    return 0;
}
