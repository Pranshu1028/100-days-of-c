/*
Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.
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
    int m, n, first[1000], second[1000], i = 0, j = 0, first_output = 1;
    if (scanf("%d", &m) != 1 || m < 0 || m > 1000) return 1;
    for (int k = 0; k < m; ++k)
        if (scanf("%d", &first[k]) != 1 ||
            (k > 0 && first[k] < first[k - 1])) return 1;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000 || m + n > 1000) return 1;
    for (int k = 0; k < n; ++k)
        if (scanf("%d", &second[k]) != 1 ||
            (k > 0 && second[k] < second[k - 1])) return 1;
    while (i < m || j < n) {
        int value = j == n || (i < m && first[i] <= second[j])
                        ? first[i++] : second[j++];
        printf("%s%d", first_output ? "" : " ", value);
        first_output = 0;
    }
    putchar('\n');
    return 0;
}
