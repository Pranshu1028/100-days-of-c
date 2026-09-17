/*
Multiply two matrices.
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
    int rows, shared, other_rows, cols;
    int a[100][100], b[100][100];
    long long product[100][100] = {{0}};
    if (scanf("%d %d", &rows, &shared) != 2 ||
        rows < 1 || rows > 100 || shared < 1 || shared > 100) return 1;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < shared; ++c)
            if (scanf("%d", &a[r][c]) != 1) return 1;
    if (scanf("%d %d", &other_rows, &cols) != 2 ||
        other_rows != shared || cols < 1 || cols > 100) {
        fprintf(stderr, "Matrix dimensions cannot be multiplied.\n");
        return 1;
    }
    for (int r = 0; r < other_rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", &b[r][c]) != 1) return 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            for (int k = 0; k < shared; ++k) {
                long long term = (long long)a[r][k] * b[k][c];
                if ((term > 0 && product[r][c] > LLONG_MAX - term) ||
                    (term < 0 && product[r][c] < LLONG_MIN - term)) {
                    fprintf(stderr, "Matrix product exceeds the supported range.\n");
                    return 1;
                }
                product[r][c] += term;
            }
        }
    }
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c)
            printf("%s%d", c == 0 ? "" : " ", product[r][c]);
        putchar('\n');
    }
    return 0;
}
